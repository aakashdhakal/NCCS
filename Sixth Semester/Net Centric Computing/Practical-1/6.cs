// Create a class EmployeeDetails having data member empId, empName, empGender,
// empAddress, and empPosition, constructor to set the details and display method to display
// the details. Create a subclass SalaryInfo that will inherit EmployeeDetails having own data
// member salary which will record salary per year, constructor to set the value of salary and
// method calcTax() that deduct the tax on salary and display the final salary. Tax rate is given
// as (if salary <= 400000 tax is 1%, salary between 400001 to 800000 tax is 10% and salary
// > 800000 tax 20%). Now create the object of Salary info and demonstrate the scenario.

using System;

namespace Question_6
{
    public class EmployeeDetails
    {
        public int EmpId { get; set; }
        public string EmpName { get; set; }
        public string EmpGender { get; set; }
        public string EmpAddress { get; set; }
        public string EmpPosition { get; set; }

        public EmployeeDetails(int empId, string empName, string empGender, string empAddress, string empPosition)
        {
            EmpId = empId;
            EmpName = empName;
            EmpGender = empGender;
            EmpAddress = empAddress;
            EmpPosition = empPosition;
        }

        public void DisplayDetails()
        {
            Console.WriteLine($"ID: {EmpId}");
            Console.WriteLine($"Name: {EmpName}");
            Console.WriteLine($"Gender: {EmpGender}");
            Console.WriteLine($"Address: {EmpAddress}");
            Console.WriteLine($"Position: {EmpPosition}");
        }
    }

    public class SalaryInfo : EmployeeDetails
    {
        public double Salary { get; set; }

        public SalaryInfo(int empId, string empName, string empGender, string empAddress, string empPosition, double salary)
            : base(empId, empName, empGender, empAddress, empPosition)
        {
            Salary = salary;
        }

        public void CalcTax()
        {
            double taxRate;
            if (Salary <= 400000)
            {
                taxRate = 0.01;
            }
            else if (Salary <= 800000)
            {
                taxRate = 0.10;
            }
            else
            {
                taxRate = 0.20;
            }

            double tax = Salary * taxRate;
            double finalSalary = Salary - tax;

            Console.WriteLine($"Salary: {Salary}");
            Console.WriteLine($"Tax Rate: {taxRate * 100}%");
            Console.WriteLine($"Tax Amount: {tax}");
            Console.WriteLine($"Final Salary after Tax: {finalSalary}");
            Console.WriteLine();
        }
    }

    public class Program
    {
        public  void Main(string[] args)
        {
            SalaryInfo employee1 = new SalaryInfo(1, "Aakash Dhakal", "Male", "Gothatar", "Developer", 350000);
            employee1.DisplayDetails();
            employee1.CalcTax();

            SalaryInfo employee2 = new SalaryInfo(2, "Archana Subedi", "Female", "Jhapa", "Manager", 600000);
            employee2.DisplayDetails();
            employee2.CalcTax();

            SalaryInfo employee3 = new SalaryInfo(3, "Amardeep Limbu", "Male", "Kapan", "CEO", 1200000);
            employee3.DisplayDetails();
            employee3.CalcTax();


            Console.ReadKey();
        }
    }
}