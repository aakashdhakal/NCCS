// 2. Write a program to demonstrate exception handline (try, catch, throw throws)

using System;

namespace Question_12
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Console.Write("Enter a number: ");
                int number = Convert.ToInt32(Console.ReadLine());
                if (number < 0)
                {
                    throw new ArgumentException("Number cannot be negative");
                }
                Console.WriteLine("You entered: " + number);
            }
            catch (FormatException ex)
            {
                Console.WriteLine("Input was not a valid number. " + ex.Message);
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }
            catch (Exception ex)
            {
                Console.WriteLine("An unexpected error occurred. " + ex.Message);
            }
            finally
            {
                Console.WriteLine("Execution completed.");
            }

            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
        }
    }
}