<?php


function get_iot_devices($conn)
{

	$thereturn = '';
	try {

    $stmt = $conn->prepare("SELECT DISTINCT iot_id FROM readings ");
    $stmt->execute();


    $iot_devices = $stmt->fetchAll();

}
catch(PDOException $e) {
    echo "Error: " . $e->getMessage();
}
$conn = null;

return $iot_devices;

}


function get_readings_for_Device_id_By_property($conn,$dev_id,$property)
{

	$thereturn = '';
	try {

    $stmt = $conn->prepare("SELECT entry_id, iot_id, timestamp, value FROM readings WHERE property = $property AND iot_id = '$dev_id'");
    $stmt->execute();


    $temperature = $stmt->fetchAll();
  
}
catch(PDOException $e) {
    echo "Error: " . $e->getMessage();
}
$conn = null;

return $temperature;

}


function insert_to_readings_from_Iot($conn,$iot_id,$property,$value)
{

	try {
   

    $sql = "INSERT INTO readings (iot_id,property, value)
    VALUES ('$iot_id', $property , $value )";
    // use exec() because no results are returned
    $conn->exec($sql);
    echo "New record created successfully";
    }
catch(PDOException $e)
    {
    echo $sql . "<br>" . $e->getMessage();
    }

$conn = null;


}

?>
