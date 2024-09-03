<?php
$servername = "localhost";
$username = "root";
$password = "";

// Create connection
$conn = mysqli_connect($servername, $username, $password);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Create database
$sql = "CREATE DATABASE webTechLab";
if (mysqli_query($conn, $sql) === TRUE) {
    echo "Database created successfully";
} else {
    echo "Error creating database: " . mysqli_error($conn);
}

// Close connection
mysqli_close($conn);


$firstName = "Aakash";
$lastName = "Dhakal";

//string operations
echo "Concatenation: " . $firstName . " " . $lastName . "<br>";
echo "Length of firstName: " . strlen($firstName) . "<br>";
echo "Length of lastName: " . strlen($lastName) . "<br>";
echo "Substring: " . substr($firstName, 0, 3) . "<br>";
echo "Position of 'k' in firstName: " . strpos($firstName, 'k') . "<br>";
echo "Uppercase: " . strtoupper($firstName) . "<br>";
echo "Lowercase: " . strtolower($lastName) . "<br>";
echo "Replace: " . str_replace("Dhakal", "D", $lastName) . "<br>";
?>