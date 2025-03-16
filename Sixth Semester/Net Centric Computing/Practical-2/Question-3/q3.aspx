<%@ Page Language="C#" AutoEventWireup="true" CodeFile="q3.aspx.cs" Inherits="project.q3" %>
<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>User Registration</title>
</head>
<body>
    <form id="form1" runat="server">
        <h2>User Registration</h2>
        
        <label>Username:</label>
        <asp:TextBox ID="txtUsername" runat="server"></asp:TextBox>
        <asp:RequiredFieldValidator ControlToValidate="txtUsername" ErrorMessage="Username is required!" ForeColor="Red" runat="server" /><br><br>

        <label>Password:</label>
        <asp:TextBox ID="txtPassword" runat="server" TextMode="Password"></asp:TextBox>
        <asp:RequiredFieldValidator ControlToValidate="txtPassword" ErrorMessage="Password is required!" ForeColor="Red" runat="server" /><br><br>

        <label>Re-enter Password:</label>
        <asp:TextBox ID="txtRepassword" runat="server" TextMode="Password"></asp:TextBox>
        <asp:RequiredFieldValidator ControlToValidate="txtRepassword" ErrorMessage="Re-enter password!" ForeColor="Red" runat="server" />
        <asp:CompareValidator ControlToValidate="txtRepassword" ControlToCompare="txtPassword" ErrorMessage="Passwords do not match!" ForeColor="Red" runat="server" /><br><br>

           <asp:Label ID="l6" Text="Gender" runat="server"></asp:Label>
            <asp:RadioButton ID="rb1" GroupName="gender" Text="Male" runat="server" />
            <asp:RadioButton ID="rb2" GroupName="gender" Text="Female" runat="server" />
            <br />

        <label>Course:</label>
        <asp:CheckBox ID="csit" runat="server" Text="CSIT" />
        <asp:CheckBox ID="bbm" runat="server" Text="BBM" />
        <asp:CheckBox ID="bim" runat="server" Text="BIM" />
       <br />

        <label>Country:</label>
        <asp:DropDownList ID="ddlCountry" runat="server">
            <asp:ListItem Text="Select Country" Value="" />
            <asp:ListItem Text="Nepal" Value="Nepal" />
            <asp:ListItem Text="India" Value="India" />
            <asp:ListItem Text="USA" Value="USA" />
        </asp:DropDownList>
        <asp:RequiredFieldValidator ControlToValidate="ddlCountry" InitialValue="" ErrorMessage="Select a country!" ForeColor="Red" runat="server" /><br><br>

        <asp:Button ID="btnSubmit" runat="server" Text="Register" OnClick="btnSubmit_Click" />
    </form>
</body>
</html>