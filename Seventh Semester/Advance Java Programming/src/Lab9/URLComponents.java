package Lab9;

import java.net.URL;

public class URLComponents {
    public static void main(String[] args) throws Exception {
        URL url = new URL("https://www.example.com:443/page/index.html?user=admin&ref=123");
        System.out.println("Protocol: " + url.getProtocol());
        System.out.println("Host: " + url.getHost());
        System.out.println("Port: " + url.getPort());
        System.out.println("Path: " + url.getPath());
        System.out.println("File: " + url.getFile());
        System.out.println("Query: " + url.getQuery());
    }
}