using System;
using System.Data.SqlClient;
using System.Web.UI;

namespace project
{
    public partial class q3 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnSubmit_Click(object sender, EventArgs e)
        {
            try
            {
                string username = txtUsername.Text.Trim();
                string password = txtPassword.Text.Trim();
                string repassword = txtRepassword.Text.Trim();
                string gender = rb1.Checked ? "Male" : "Female";

                // Collect selected courses
                string courses = "";
                if (csit.Checked) courses += "CSIT, ";
                if (bbm.Checked) courses += "BBM, ";
                if (bim.Checked) courses += "BIM, ";
                courses = courses.TrimEnd(',', ' ');

                string country = ddlCountry.SelectedValue;

                if (string.IsNullOrEmpty(username) || string.IsNullOrEmpty(password) || string.IsNullOrEmpty(repassword))
                {
                    Response.Write("<script>alert('All fields are required!');</script>");
                    return;
                }

                if (password != repassword)
                {
                    Response.Write("<script>alert('Passwords do not match!');</script>");
                    return;
                }

                string connString = "Data Source=AAKASH-DHAKAL;Initial Catalog=dotnet;Integrated Security=True;TrustServerCertificate=True";
                using (SqlConnection conn = new SqlConnection(connString))
                {
                    conn.Open();
                    Random rand = new Random();
                    int randomId = rand.Next(10000, 99999);
                    string query = "INSERT INTO tbl_registration (id, username, password, repassword, gender, course, country) " +
                        "VALUES (@id, @username, @password, @repassword, @gender, @course, @country)";

                    using (SqlCommand cmd = new SqlCommand(query, conn))
                    {
                        cmd.Parameters.AddWithValue("@id", randomId);
                        cmd.Parameters.AddWithValue("@username", username);
                        cmd.Parameters.AddWithValue("@password", password);
                        cmd.Parameters.AddWithValue("@repassword", repassword);
                        cmd.Parameters.AddWithValue("@gender", gender);
                        cmd.Parameters.AddWithValue("@course", courses);
                        cmd.Parameters.AddWithValue("@country", country);

                        int rows = cmd.ExecuteNonQuery();
                        if (rows > 0)
                        {
                            Response.Write("<script>alert('Registration Successful!');</script>");
                        }
                        else
                        {
                            Response.Write("<script>alert('Error in registration!');</script>");
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Response.Write("<script>alert('An error occurred: " + ex.Message + "');</script>");
            }
        }
    }
}
