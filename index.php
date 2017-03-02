<?php
  include('serv_config.php');
  include('php_functions.php');

$iot_devices = get_iot_devices($dbh);
foreach($iot_devices as $device)
{
 
$tempdata = get_readings_for_Device_id_By_property($dbh,$device['iot_id'],'1');
}


echo json_encode($tempdata);

?>

  
