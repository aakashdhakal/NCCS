using System;
using System.Collections.Generic;

namespace project
{
    public partial class q1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
        }

        protected void btnAdd_Click(object sender, EventArgs e)
        {
            try
            {
                int firstNumber = int.Parse(txtFirstNumber.Text);
                int secondNumber = int.Parse(txtSecondNumber.Text);
                int result = firstNumber + secondNumber;
                txtResult.Text = "Sum: " + result.ToString();
            }
            catch (FormatException)
            {
                txtResult.Text = "Please enter valid numbers.";
            }
        }

        protected void btnSubtract_Click(object sender, EventArgs e)
        {
            try
            {
                int firstNumber = int.Parse(txtFirstNumber.Text);
                int secondNumber = int.Parse(txtSecondNumber.Text);
                int result = firstNumber - secondNumber;
                txtResult.Text = "Difference: " + result.ToString();
            }
            catch (FormatException)
            {
                txtResult.Text = "Please enter valid numbers.";
            }
        }

        protected void btnFindPrime_Click(object sender, EventArgs e)
        {
            try
            {
                int start = int.Parse(txtFirstNumber.Text);
                int end = int.Parse(txtSecondNumber.Text);

                if (start > end)
                {
                    txtResult.Text = "Start number must be less than or equal to the end number.";
                    return;
                }

                List<int> primeNumbers = new List<int>();

                for (int i = start; i <= end; i++)
                {
                    if (IsPrime(i))
                    {
                        primeNumbers.Add(i);
                    }
                }

                txtResult.Text = primeNumbers.Count > 0
                    ? "Prime numbers: " + string.Join(", ", primeNumbers)
                    : "No prime numbers found in the range.";
            }
            catch (FormatException)
            {
                txtResult.Text = "Please enter valid numbers.";
            }
        }

        private bool IsPrime(int number)
        {
            if (number <= 1) return false;
            if (number == 2) return true;
            if (number % 2 == 0) return false;

            for (int i = 3; i <= Math.Sqrt(number); i += 2)
            {
                if (number % i == 0) return false;
            }
            return true;
        }
    }
}