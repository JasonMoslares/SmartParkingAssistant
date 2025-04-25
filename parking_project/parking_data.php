<?php

$hostname = "localhost";
$username = "root";
$password = ""; //Leave blank if you don't have any password
$database = "parking"; //Change to any database name

$conn = mysqli_connect($hostname, $username, $password, $database, 3307); //3307 is the port number of MySQL in my PC

if(!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

echo "Database connection is OK", PHP_EOL;

if (isset($_POST["id1"]) && isset($_POST["status1"])) {
    $id1 = $_POST["id1"];
    $status1 = $_POST["status1"];
    $sql1 = "UPDATE photosensor SET status = '$status1' WHERE id = $id1";
    $conn->query($sql1);
    echo "Statuses updated.";
}

if (isset($_POST["id2"]) && isset($_POST["status2"])) {
    $id2 = $_POST["id2"];
    $status2 = $_POST["status2"];
    $sql2 = "UPDATE photosensor SET status = '$status2' WHERE id = $id2";
    $conn->query($sql2);
    echo "Statuses updated.";
}

else {
    echo "Missing data.";
}

?>