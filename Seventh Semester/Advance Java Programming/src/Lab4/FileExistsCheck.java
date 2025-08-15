package Lab4;

import java.io.File;

public class FileExistsCheck {
    public static void main(String[] args) {
        String path = "C:\\Users\\YourUsername\\Desktop\\test.txt"; // Change path as needed
        File file = new File(path);
        if (file.exists()) {
            System.out.println("File exists.");
        } else {
            System.out.println("File does not exist.");
        }
    }
}