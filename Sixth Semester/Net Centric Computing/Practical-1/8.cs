//Write a program to demonstrate use of base keyword

using System;

namespace Question_8
{
    class Animal
    {
        public virtual void MakeSound()
        {
            Console.WriteLine("Animal makes a sound");
        }
    }

    class Dog : Animal
    {
        public override void MakeSound()
        {
            base.MakeSound();
            Console.WriteLine("Dog barks");
        }
    }

    class Program
    {
        static void Main()
        {
            Dog myDog = new Dog();
            myDog.MakeSound();
            Console.ReadKey();
        }
    }
}