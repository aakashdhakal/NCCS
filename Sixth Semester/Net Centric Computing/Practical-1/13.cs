// Write a program to demonstrate interface

using System;

namespace Question_13
{
    interface IAnimal
    {
        void MakeSound();
    }

    class Dog : IAnimal
    {
        public void MakeSound()
        {
            Console.WriteLine("Woof!");
        }
    }

    class Cat : IAnimal
    {
        public void MakeSound()
        {
            Console.WriteLine("Meow!");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            IAnimal dog = new Dog();
            IAnimal cat = new Cat();

            dog.MakeSound();
            cat.MakeSound();
            Console.ReadKey();
        }
    }
}