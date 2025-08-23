package Lab8;

import java.sql.*;
import java.util.Scanner;

public class StudentCRUD {
    static final String URL = "jdbc:mysql://localhost:3306/jdbc";
    static final String USER = "root";
    static final String PASS = "";

    public static void main(String[] args) {
        try {
            Connection con = DriverManager.getConnection(URL, USER, PASS);
            Scanner sc = new Scanner(System.in);
            // Create table if not exists
            String createTable = "CREATE TABLE IF NOT EXISTS student (id INT PRIMARY KEY, name VARCHAR(50), age INT, address VARCHAR(100), email VARCHAR(50) UNIQUE, phone VARCHAR(20) UNIQUE)";
            con.createStatement().execute(createTable);

            while (true) {
                System.out.println("\n1. Create \n2. Read \n3. Update \n4. Delete \n5. Exit");
                System.out.print("Enter choice: ");
                int ch = sc.nextInt();
                if (ch == 5)
                    break;
                switch (ch) {
                case 1: // Create
                    System.out.print("ID: ");
                    int id = sc.nextInt();
                    System.out.print("Name: ");
                    sc.nextLine();
                    String name = sc.nextLine();
                    System.out.print("Age: ");
                    int age = sc.nextInt();
                    System.out.print("Address: ");
                    sc.nextLine();
                    String addr = sc.nextLine();
                    System.out.print("Email: ");
                    String email = sc.next();
                    System.out.print("Phone: ");
                    String phone = sc.next();
                    String ins = "INSERT INTO student VALUES (?, ?, ?, ?, ?, ?)";
                    PreparedStatement ps = con.prepareStatement(ins);
                    ps.setInt(1, id);
                    ps.setString(2, name);
                    ps.setInt(3, age);
                    ps.setString(4, addr);
                    ps.setString(5, email);
                    ps.setString(6, phone);
                    ps.executeUpdate();
                    System.out.println("Student added.");
                    break;
                case 2: // Read
                    ResultSet rs = con.createStatement().executeQuery("SELECT * FROM student");
                    System.out.println("ID\tName\t\tAge\tAddress\t\tEmail\t\t\t\tPhone");
                    while (rs.next()) {
                        System.out.printf("%d\t%s\t%d\t%s\t%s\t%s\n", rs.getInt("id"), rs.getString("name"),
                                rs.getInt("age"), rs.getString("address"), rs.getString("email"),
                                rs.getString("phone"));
                    }
                    break;
                case 3: // Update
                    System.out.print("Enter ID to update: ");
                    int uid = sc.nextInt();
                    System.out.print("New Name: ");
                    sc.nextLine();
                    String nname = sc.nextLine();
                    System.out.print("New Age: ");
                    int nage = sc.nextInt();
                    System.out.print("New Address: ");
                    sc.nextLine(); // consume leftover newline
                    String naddr = sc.nextLine();
                    System.out.print("New Email: ");
                    String nemail = sc.next();
                    System.out.print("New Phone: ");
                    String nphone = sc.next();
                    String upd = "UPDATE student SET name=?, age=?, address=?, email=?, phone=? WHERE id=?";
                    PreparedStatement psUpd = con.prepareStatement(upd);
                    psUpd.setString(1, nname);
                    psUpd.setInt(2, nage);
                    psUpd.setString(3, naddr);
                    psUpd.setString(4, nemail);
                    psUpd.setString(5, nphone);
                    psUpd.setInt(6, uid);
                    int rows = psUpd.executeUpdate();
                    System.out.println(rows > 0 ? "Updated." : "ID not found.");

                    break;
                case 4: // Delete
                    System.out.print("Enter ID to delete: ");
                    int did = sc.nextInt();
                    String del = "DELETE FROM student WHERE id=?";
                    PreparedStatement psDel = con.prepareStatement(del);
                    psDel.setInt(1, did);
                    int delRows = psDel.executeUpdate();
                    System.out.println(delRows > 0 ? "Deleted." : "ID not found.");

                    break;
                default:
                    System.out.println("Invalid choice.");
                }
            }
            sc.close();
        } catch (SQLException e) {
            System.out.println("Connection error: " + e.getMessage());
        }
    }
}