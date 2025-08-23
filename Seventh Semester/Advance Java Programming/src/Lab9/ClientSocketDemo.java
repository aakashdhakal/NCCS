package Lab9;

import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class ClientSocketDemo {
    public static void main(String[] args) {
        try {
            // Create a socket to connect to the server on localhost at port 12345
            Socket socket = new Socket("localhost", 12345);

            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            Scanner in = new Scanner(socket.getInputStream());

            // Read welcome message from the server
            String welcomeMessage = in.nextLine();
            System.out.println("Server: " + welcomeMessage);

            // Send a message to the server
            String message = "Hello, Server this is a message from client";
            out.println(message);
            System.out.println("Sent to server: " + message);

            // Read echo message from the server
            String echoMessage = in.nextLine();
            System.out.println("Server Echo: " + echoMessage);

            // Close the socket
            in.close();
            out.close();
            socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
