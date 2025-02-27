using System;
namespace Practical_1
{
    class Program
    {
        static void Main(string[] args)
        {
            // Create an object of Person class
            Person person = new("John Doe", 25);
            Console.WriteLine("Name: " + person.Name);
            Console.ReadKey();
        }
    }
}
