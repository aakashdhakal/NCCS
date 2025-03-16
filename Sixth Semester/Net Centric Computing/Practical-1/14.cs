//Write a program to demonstrate lamda expression

using System;

namespace Question_14
{
    class Program
    {
        static void Main()
        {
            Func<int, int> square = x => x * x;  // Lambda expression to square a number

            Console.WriteLine("Square of 5: " + square(5));  // Output: Square of 5: 25
            Console.ReadKey();
        }
    }
}
