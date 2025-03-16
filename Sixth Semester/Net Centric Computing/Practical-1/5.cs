// Create a class Shape that contains instance variable length, breadth and height. Create a
// default constructor that sets the value of instance variable to zero, constructor with two
// parameter that will sets the value of length and breadth only and constructor with three
// parameter that will sets the value of length, breadth and height. After this create
// calcAreaRectangle() that calculates the area of rectangle, calcVolumeBox() that calculates
// volume of box and display the result. Now create first object of Shape wihich will have
// name rectangle and calls constructor with two parameter and calAreaRectangle() method,
// create second object of Shape that will have name Box which will call constructor with
// three parameter and calcVolumeBox() method

using System;

namespace Question_5
{
    public class Shape
    {
        private double length;
        private double breadth;
        private double height;

        // Default constructor
        public Shape()
        {
            length = 0;
            breadth = 0;
            height = 0;
        }

        // Constructor with two parameters
        public Shape(double length, double breadth)
        {
            this.length = length;
            this.breadth = breadth;
            this.height = 0;
        }

        // Constructor with three parameters
        public Shape(double length, double breadth, double height)
        {
            this.length = length;
            this.breadth = breadth;
            this.height = height;
        }

        // Method to calculate the area of a rectangle
        public double CalcAreaRectangle()
        {
            return length * breadth;
        }

        // Method to calculate the volume of a box
        public double CalcVolumeBox()
        {
            return length * breadth * height;
        }

        // Method to display the result
        public void DisplayResult()
        {
            if (height == 0)
            {
                Console.WriteLine("Area of Rectangle: " + CalcAreaRectangle());
            }
            else
            {
                Console.WriteLine("Volume of Box: " + CalcVolumeBox());
            }
        }
    }

    public class Program
    {
        public static void Main(string[] args)
        {
            // Create first object of Shape with two parameters
            Shape rectangle = new Shape(5, 10);
            rectangle.DisplayResult();

            // Create second object of Shape with three parameters
            Shape box = new Shape(5, 10, 15);
            box.DisplayResult();
            Console.ReadKey();
        }
    }
}