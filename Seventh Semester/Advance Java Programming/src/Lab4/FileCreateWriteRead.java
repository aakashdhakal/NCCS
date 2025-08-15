package Lab4;

import java.io.*;

public class FileCreateWriteRead {
    public static void main(String[] args) {
        try {
            String user = System.getProperty("user.name");
            String desktopPath = "C:\\Users\\" + user + "\\Desktop\\YourName.txt";
            File file = new File(desktopPath);

            // Write to file
            PrintWriter writer = new PrintWriter(new FileWriter(file));
            writer.println("Hello, this is a test file written by Java.");
            writer.println("You can add more lines here.");
            writer.close();

            // Read file line by line
            BufferedReader reader = new BufferedReader(new FileReader(file));
            String line;
            System.out.println("File content:");
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
            reader.close();
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}