using System;

namespace Practical_1
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
        }
    }

}