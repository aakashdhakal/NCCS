// Write a program to demonstrate method overriding (dynamic polymorphism)?
using System;

namespace Question_9
{
    class Animal
    {
        public virtual void MakeSound()
        {
            Console.WriteLine("The animal makes a sound");
        }
    }

    class Dog : Animal
    {
        public override void MakeSound()
        {
            Console.WriteLine("The dog barks");
        }
    }

    class Cat : Animal
    {
        public override void MakeSound()
        {
            Console.WriteLine("The cat meows");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Animal myAnimal = new Animal();
            Animal myDog = new Dog();
            Animal myCat = new Cat();

            myAnimal.MakeSound();
            myDog.MakeSound();
            myCat.MakeSound();
            Console.ReadKey();
        }
    }
}