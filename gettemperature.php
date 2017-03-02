<?php

// check if values are set to proceed
if(isset($_GET['id']) && isset($_GET['temp']) && isset($_GET['hum']) && isset($_GET['gas']) )
{
	include('serv_config.php');
	  include('php_functions.php');
// you will have to escape special characters
$iot_id = $_GET['id'];
$temp = $_GET['temp'];
$hum = $_GET['hum'];
$gas = $_GET['gas'];

// insert to database
insert_to_readings_from_Iot($dbh,$iot_id,'1',$temp);
insert_to_readings_from_Iot($dbh,$iot_id,'2',$hum);
insert_to_readings_from_Iot($dbh,$iot_id,'3',$gas);


}// end if get values are set

?>
