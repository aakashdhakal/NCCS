package Lab10;

import java.io.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

@WebServlet(name = "helloServlet", value = "/session-cookie")
public class SessionCookie extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        // --- Cookie Example ---
        String cookieName = "user";
        String user = request.getParameter("name");
        if (user != null && !user.isEmpty()) {
            Cookie cookie = new Cookie(cookieName, user);
            cookie.setMaxAge(60 * 60); // 1 hour
            response.addCookie(cookie);
        } else {
            // Try to get from cookie
            Cookie[] cookies = request.getCookies();
            if (cookies != null) {
                for (Cookie c : cookies) {
                    if (cookieName.equals(c.getName())) {
                        user = c.getValue();
                        break;
                    }
                }
            }
        }
        if (user == null || user.isEmpty())
            user = "Guest";

        // --- Session Example ---
        HttpSession session = request.getSession();
        Integer visitCount = (Integer) session.getAttribute("visitCount");
        if (visitCount == null)
            visitCount = 1;
        else
            visitCount++;
        session.setAttribute("visitCount", visitCount);

        // --- Output ---
        out.println("<html><body>");
        out.println("<h1>Hello, " + user + "!</h1>");
        out.println("<p>Session visit count: " + visitCount + "</p>");
        out.println("<form method='get'>");
        out.println("Enter your name: <input type='text' name='name'/>");
        out.println("<input type='submit' value='Set Name'/>");
        out.println("</form>");
        out.println("</body></html>");
    }
}