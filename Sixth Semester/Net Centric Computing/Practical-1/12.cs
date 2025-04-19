//Write a program to demonstrate exception handline (try, catch, throw throws)
using System;

public class Program
{
     void Main()
    {
        try
        {
            Console.Write("Enter a number to divide 10 by: ");
            int num = Convert.ToInt32(Console.ReadLine());  // Read user input

            if (num == 0)
            {
                throw new DivideByZeroException("Cannot divide by zero");
            }

            int result = 10 / num;
            Console.WriteLine("Result: " + result);
        }
        catch (DivideByZeroException ex)
        {
            Console.WriteLine("Error: " + ex.Message);  // Catch division by zero error
        }
        catch (Exception ex)  // Catch any other errors
        {
            Console.WriteLine("Error: " + ex.Message);
        }
        Console.ReadKey();  // Wait for user input before closing
    }
}