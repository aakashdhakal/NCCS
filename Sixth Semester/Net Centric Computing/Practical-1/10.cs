using System;

namespace Question_10
{
    interface IFirst
    {
        void FirstMethod();
    }

    interface ISecond
    {
        void SecondMethod();
    }

    class MultipleInheritance : IFirst, ISecond
    {
        public void FirstMethod()
        {
            Console.WriteLine("First method implementation.");
        }

        public void SecondMethod()
        {
            Console.WriteLine("Second method implementation.");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            MultipleInheritance obj = new MultipleInheritance();
            obj.FirstMethod();
            obj.SecondMethod();
            Console.ReadKey();
        }
    }
}