<?php

$hostname = "localhost";
$username = "root";
$password = "your_pass";
$database = "parking";

$conn = mysqli_connect($hostname, $username, $password, $database, 3307);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

echo "Database connection is OK", PHP_EOL;

if (isset($_POST["id"]) && isset($_POST["status"])) {
    $id = $_POST["id"];
    $status = $_POST["status"];

    $sql = "UPDATE photosensor SET status = '$status' WHERE id = $id";

    if (mysqli_query($conn, $sql)) {
        echo "Plant $id data updated successfully.";
    } else {
        echo "Error updating data for plant $id: " . mysqli_error($conn);
    }
} else {
    echo "Missing data.";
}

mysqli_close($conn);
