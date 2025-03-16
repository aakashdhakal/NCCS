using System;

namespace Question_1
{
    class Person
    {
        // Properties
        public string Name { get; set; }
        public int Age { get; set; }

        // Constructor
        public Person(string name, int age)
        {
            Name = name;
            Age = age;
        }

        // Method
        public void DisplayInfo()
        {
            Console.WriteLine("Name: " + Name);
            Console.WriteLine("Age: " + Age);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Person person = new Person("Aakash", 22);
            person.DisplayInfo();
            Console.ReadKey();
        }
    }
}