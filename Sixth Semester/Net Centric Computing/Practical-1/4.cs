// Create a class Number having instance variable x and y both in integer, default constructor
// that set the value of x and y to 0, parameterized constructor that sets the value of x and y,
// method findOdd() that calculates the even no. occurring between x and y and display the
// result, findEven() that calculates the odd no. occurring between x and y and display the
// results. Now, create some instance of Number and invoke all the methods

using System;
namespace Question_4
{
    public class Number
    {
        private int x;
        private int y;

        // Default constructor
        public Number()
        {
            x = 0;
            y = 0;
        }

        // Parameterized constructor
        public Number(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        // Method to find and display even numbers between x and y
        public void FindEven()
        {
            Console.Write("Even numbers between {0} and {1}: ", x, y);
            for (int i = x; i <= y; i++)
            {
                if (i % 2 == 0)
                {
                    Console.Write(i + " ");
                }
            }
            Console.WriteLine("\n");
        }

        // Method to find and display odd numbers between x and y
        public void FindOdd()
        {
            Console.Write("Odd numbers between {0} and {1}: ", x, y);
            for (int i = x; i <= y; i++)
            {
                if (i % 2 != 0)
                {
                    Console.Write(i + " ");
                }
            }
            Console.WriteLine("\n");
        }

        public  void Main(string[] args)
        {
            // Creating instances of Number
            Number num1 = new Number();
            Number num2 = new Number(1, 10);

            // Invoking methods
            num1.FindEven();
            num1.FindOdd();

            num2.FindEven();
            num2.FindOdd();
            Console.ReadKey();
        }
    }
}