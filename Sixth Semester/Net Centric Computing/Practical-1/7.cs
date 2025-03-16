//Write a program to demonstrate single level, multilevel inheritance?

using System;

namespace Question_7
{
    class Vehicle
    {
        public void Start()
        {
            Console.WriteLine("Vehicle started...");
        }
    }

    class Car : Vehicle
    {
        public void Drive()
        {
            Console.WriteLine("Car is driving...");
        }
    }

    class SportsCar : Car
    {
        public void TurboBoost()
        {
            Console.WriteLine("Turbo boost activated...");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Single level inheritance
            Car car = new Car();
            car.Start();
            car.Drive();

            // Multilevel inheritance
            SportsCar sportsCar = new SportsCar();
            sportsCar.Start();
            sportsCar.Drive();
            sportsCar.TurboBoost();
            Console.ReadKey();
        }
    }
}