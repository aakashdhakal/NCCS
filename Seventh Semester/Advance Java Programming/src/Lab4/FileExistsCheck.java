package Lab4;

import java.io.File;

public class FileExistsCheck {
    public static void main(String[] args) {
        String path = "C:\\Users\\anamo\\OneDrive\\Desktop\\notExists.txt"; // Change path as needed
        File file = new File(path);
        if (file.exists()) {
            System.out.println("File exists at path: " + path);
        } else {
            System.out.println("File does not exist at path: " + path);
        }
    }
}