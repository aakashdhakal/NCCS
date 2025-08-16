package Lab9;

import java.io.PrintWriter;
import java.net.*;
import java.util.Scanner;

public class ServerSocketDemo {
    public static void main(String[] args) {
        try {
            // Create a server socket on port 12345
            ServerSocket serverSocket = new ServerSocket(12345);
            Socket socket = serverSocket.accept();

            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            Scanner in = new Scanner(socket.getInputStream());

            System.out.println("Client connected: " + socket.getInetAddress() + ":" + socket.getPort());

            // Send a welcome message to the client
            out.println("Welcome to the server!");
            System.out.println("Sent welcome message to client.");
            // Read a message from the client
            String clientMessage = in.nextLine();
            System.out.println("Received from client: " + clientMessage);
            // Echo the message back to the client
            out.println("Echo: " + clientMessage);
            System.out.println("Sent echo message to client.");

            // Close the socket
            in.close();
            out.close();
            serverSocket.close();
            socket.close();
            System.out.println("Connection closed.");

        } catch (Exception e) {
            e.printStackTrace();
        }

    }

}
