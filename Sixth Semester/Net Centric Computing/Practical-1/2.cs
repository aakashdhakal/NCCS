// Write a program to demonstrate method overloading?


using System;

namespace Question_2
{
    class Program
    {

        static int Add(int a, int b)
        {
            return a + b;
        }

        static int Add(int a, int b, int c)
        {
            return a + b + c;
        }

        static double Add(double a, double b)
        {
            return a + b;
        }
         void Main(string[] args)
        {
            Console.WriteLine(Add(5, 10));
            Console.WriteLine(Add(5.5, 10.5));
            Console.WriteLine(Add(5, 10, 15));
            Console.ReadKey();
        }
    }
}