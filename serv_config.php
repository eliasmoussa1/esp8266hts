<?php
// database configuration

define("DB_USER", "entervaluehere");
define("DB_PASSWORD","entervaluehere");
define("DB_HOST","localhost");
define("DB_NAME","IoT");
define("SECURE", FALSE);
$dbh = new PDO("mysql:host=".DB_HOST.";dbname=".DB_NAME, DB_USER, DB_PASSWORD);
$dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);


?>
