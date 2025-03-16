// Write a console program (ADO.net) to create a table tbl_registration that have fields (id int
// primary key, username, password, repassword, gender, course and country). After this perform
// the following operation
// • Insert any 5 data into tbl_registration. All the required input should be taken from user
// • Display all the record of database table
// • Update the name and course of a person to data given by user according to id given by
// user
// • Delete the record of person whose id is given by user
// • Display all the record of person who are male and also from country Nepal


using System;
using System.Data;
using Microsoft.Data.SqlClient;

class Program
{
    static void Main()
    {
        string connectionString = "Server=AAKASH-DHAKAL;Initial Catalog=dotnet;Integrated Security=True;Trusted_Connection=True;TrustServerCertificate=True;";
        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            connection.Open();

            // Create table
            string createTableQuery = @"
                CREATE TABLE tbl_registration (
                    id INT PRIMARY KEY,
                    username NVARCHAR(50),
                    password NVARCHAR(50),
                    repassword NVARCHAR(50),
                    gender NVARCHAR(10),
                    course NVARCHAR(50),
                    country NVARCHAR(50)
                )";
            SqlCommand createTableCmd = new SqlCommand(createTableQuery, connection);
            createTableCmd.ExecuteNonQuery();

            // Insert data
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine("Enter details for record {0} fucker:", i + 1);
                Console.Write("ID: ");
                int id = int.Parse(Console.ReadLine());
                Console.Write("Username: ");
                string username = Console.ReadLine();
                Console.Write("Password: ");
                string password = Console.ReadLine();
                Console.Write("Repassword: ");
                string repassword = Console.ReadLine();
                Console.Write("Gender: ");
                string gender = Console.ReadLine();
                Console.Write("Course: ");
                string course = Console.ReadLine();
                Console.Write("Country: ");
                string country = Console.ReadLine();

                string insertQuery = "INSERT INTO tbl_registration VALUES (@id, @username, @password, @repassword, @gender, @course, @country)";
                SqlCommand insertCmd = new SqlCommand(insertQuery, connection);
                insertCmd.Parameters.AddWithValue("@id", id);
                insertCmd.Parameters.AddWithValue("@username", username);
                insertCmd.Parameters.AddWithValue("@password", password);
                insertCmd.Parameters.AddWithValue("@repassword", repassword);
                insertCmd.Parameters.AddWithValue("@gender", gender);
                insertCmd.Parameters.AddWithValue("@course", course);
                insertCmd.Parameters.AddWithValue("@country", country);
                insertCmd.ExecuteNonQuery();
            }

            // Display all records
            Console.WriteLine("All records:");
            string selectAllQuery = "SELECT * FROM tbl_registration";
            SqlCommand selectAllCmd = new SqlCommand(selectAllQuery, connection);
            SqlDataReader reader = selectAllCmd.ExecuteReader();
            while (reader.Read())
            {
                Console.WriteLine("{0}, {1}, {2}, {3}, {4}, {5}, {6}", reader["id"], reader["username"], reader["password"], reader["repassword"], reader["gender"], reader["course"], reader["country"]);
            }
            reader.Close();

            // Update record
            Console.Write("Enter ID to update: ");
            int updateId = int.Parse(Console.ReadLine());
            Console.Write("Enter new username: ");
            string newUsername = Console.ReadLine();
            Console.Write("Enter new course: ");
            string newCourse = Console.ReadLine();
            string updateQuery = "UPDATE tbl_registration SET username = @newUsername, course = @newCourse WHERE id = @updateId";
            SqlCommand updateCmd = new SqlCommand(updateQuery, connection);
            updateCmd.Parameters.AddWithValue("@newUsername", newUsername);
            updateCmd.Parameters.AddWithValue("@newCourse", newCourse);
            updateCmd.Parameters.AddWithValue("@updateId", updateId);
            updateCmd.ExecuteNonQuery();

            // Delete record
            Console.Write("Enter ID to delete: ");
            int deleteId = int.Parse(Console.ReadLine());
            string deleteQuery = "DELETE FROM tbl_registration WHERE id = @deleteId";
            SqlCommand deleteCmd = new SqlCommand(deleteQuery, connection);
            deleteCmd.Parameters.AddWithValue("@deleteId", deleteId);
            deleteCmd.ExecuteNonQuery();

            // Display records of males from Nepal
            Console.WriteLine("Records of males from Nepal:");
            string selectMaleNepalQuery = "SELECT * FROM tbl_registration WHERE gender = 'Male' AND country = 'Nepal'";
            SqlCommand selectMaleNepalCmd = new SqlCommand(selectMaleNepalQuery, connection);
            SqlDataReader maleNepalReader = selectMaleNepalCmd.ExecuteReader();
            while (maleNepalReader.Read())
            {
                Console.WriteLine("{0}, {1}, {2}, {3}, {4}, {5}, {6}", maleNepalReader["id"], maleNepalReader["username"], maleNepalReader["password"], maleNepalReader["repassword"], maleNepalReader["gender"], maleNepalReader["course"], maleNepalReader["country"]);
            }
            maleNepalReader.Close();
        }
    }
}