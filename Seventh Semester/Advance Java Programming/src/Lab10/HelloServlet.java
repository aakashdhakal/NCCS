package Lab10;

import java.io.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

@WebServlet(name = "helloServlet", value = "/hello-servlet")
public class HelloServlet extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");

        // Get a "name" parameter from the URL, e.g., /hello-servlet?name=John
        String name = request.getParameter("name");
        if (name == null || name.isEmpty()) {
            name = "Guest";
        }

        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        out.println("<h1>Hello, " + name + "!</h1>");
        out.println("<form method='get'>");
        out.println("Enter your name: <input type='text' name='name'/>");
        out.println("<input type='submit' value='Greet'/>");
        out.println("</form>");
        out.println("</body></html>");
    }
}