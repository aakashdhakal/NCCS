// using System;

// namespace Demo
// {
//     public partial class _1 : System.Web.UI.Page
//     {
//         protected void Page_Load(object sender, EventArgs e)
//         {
//         }

//         protected void btnAdd_Click(object sender, EventArgs e)
//         {
//             int firstNumber = int.Parse(txtFirstNumber.Text);
//             int secondNumber = int.Parse(txtSecondNumber.Text);
//             int result = firstNumber + secondNumber;
//             txtResult.Text = "Sum: " + result.ToString();
//         }

//         protected void btnSubtract_Click(object sender, EventArgs e)
//         {
//             int firstNumber = int.Parse(txtFirstNumber.Text);
//             int secondNumber = int.Parse(txtSecondNumber.Text);
//             int result = firstNumber - secondNumber;
//             txtResult.Text = "Difference: " + result.ToString();
//         }

//         protected void btnFindPrime_Click(object sender, EventArgs e)
//         {
//             int number = int.Parse(txtFirstNumber.Text);
//             bool isPrime = IsPrime(number);
//             txtResult.Text = isPrime ? number + " is a prime number" : number + " is not a prime number";
//         }

//         private bool IsPrime(int number)
//         {
//             if (number <= 1) return false;
//             if (number == 2) return true;
//             if (number % 2 == 0) return false;

//             for (int i = 3; i <= Math.Sqrt(number); i += 2)
//             {
//                 if (number % i == 0) return false;
//             }
//             return true;
//         }
//     }
// }