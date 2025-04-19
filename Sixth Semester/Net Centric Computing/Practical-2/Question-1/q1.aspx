<%@ Page Language="C#" AutoEventWireup="true" CodeFile="q1.aspx.cs" Inherits="project.q1"%>
<html runat="server">
<head runat="server">
    <title>Number Operations</title>
</head>
<body runat="server">
<h1>Number Operations</h1>
<h4>By Aakash Dhakal</h4>
    <form id="form1" runat="server">
        <asp:Label ID="lblFirstNumber" Text="Enter first number" runat="server"></asp:Label>
        <asp:TextBox ID="txtFirstNumber" runat="server"></asp:TextBox>
        <asp:RequiredFieldValidator ID="rfvFirstNumber" ControlToValidate="txtFirstNumber" ErrorMessage="First number cannot be empty" ForeColor="Red" runat="server"></asp:RequiredFieldValidator>
        <br />
        <br />
        
        <asp:Label ID="lblSecondNumber" Text="Enter second number" runat="server"></asp:Label>
        <asp:TextBox ID="txtSecondNumber" runat="server"></asp:TextBox>
        <asp:RequiredFieldValidator ID="rfvSecondNumber" ControlToValidate="txtSecondNumber" ErrorMessage="Second number cannot be empty" ForeColor="Red" runat="server"></asp:RequiredFieldValidator>
         <br />
        <br />
        
        <asp:Button ID="btnAdd" Text="Add" OnClick="btnAdd_Click" runat="server" />
        <asp:Button ID="btnSubtract" Text="Subtract" OnClick="btnSubtract_Click" runat="server" />
        <asp:Button ID="btnFindPrime" Text="Find Prime" OnClick="btnFindPrime_Click" runat="server" />
         <br />
        <br />
        
        <asp:Label ID="lblResult" Text="Result = " runat="server"></asp:Label>
         <asp:Label ID="txtResult" Text="" runat="server"></asp:Label>
        
    </form>
</body>
</html>
