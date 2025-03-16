using System;

namespace Question_3
{
    class Program
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
        static void Main(string[] args)
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