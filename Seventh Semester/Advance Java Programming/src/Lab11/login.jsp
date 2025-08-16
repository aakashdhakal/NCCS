<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%> <% String error = null; boolean loggedIn = false; if
("POST".equalsIgnoreCase(request.getMethod())) { String user =
request.getParameter("username"); String pass =
request.getParameter("password"); if ("admin".equals(user) &&
"nccs#123".equals(pass)) { loggedIn = true; } else { error = "Invalid username
or password!"; } } %>
<!DOCTYPE html>
<html>
	<head>
		<title>Login</title>
	</head>
	<body>
		<% if (!loggedIn) { %>
		<h2>Login</h2>
		<form method="post">
			Username: <input type="text" name="username" required /><br />
			Password: <input type="password" name="password" required /><br />
			<input type="submit" value="Login" />
		</form>
		<% if (error != null) { %>
		<p style="color: red"><%= error %></p>
		<% } %> <% } else { %>
		<jsp:forward page="dashboard.jsp" />
		<% } %>
	</body>
</html>
