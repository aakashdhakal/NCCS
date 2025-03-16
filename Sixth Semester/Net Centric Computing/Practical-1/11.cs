// Write a program to demonstrate abstract class
using System;

namespace Question_11
{
    abstract class Shape
    {
        public abstract double Area();

    }

    class Circle : Shape
    {
        private double radius;

        public Circle(double radius)
        {
            this.radius = radius;
        }

        public override double Area()
        {
            return Math.PI * radius * radius;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Shape circle = new Circle(5);
            Console.WriteLine("Area of Circle: " + circle.Area());
            Console.ReadKey();
        }
    }
}