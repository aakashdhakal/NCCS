// Create a class Calculate which contains data member num1 and num2 both in integer and
// methods setCalc() to set the data, calcSum() that calculate the sum of num1 and num2 and
// display the result, calcMulti() that calculate the multiplication of num1 and num2 and
// returns the result, calcDifference that calculate the difference between num1 and num2 and
// display the result. Now, create some instance of Calculate and invoke all the methods.

using System;

namespace Question_3
{
    class Calculate
    {
        private int num1;
        private int num2;

        public void setCalc(int n1, int n2)
        {
            num1 = n1;
            num2 = n2;
        }

        public void calcSum()
        {
            int sum = num1 + num2;
            Console.WriteLine("Sum: " + sum);
        }

        public int calcMulti()
        {
            return num1 * num2;
        }

        public void calcDifference()
        {
            int difference = num1 - num2;
            Console.WriteLine("Difference: " + difference);
        }
    }
    class Program
    {

         void Main(string[] args)
        {
            Calculate calc = new Calculate();
            calc.setCalc(10, 5);
            calc.calcSum();
            Console.WriteLine("Multiplication: " + calc.calcMulti());
            calc.calcDifference();
            Console.ReadKey();
        }
    }

}