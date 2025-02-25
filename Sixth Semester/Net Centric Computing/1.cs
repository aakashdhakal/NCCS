namespace ConsoleApp
{
    public class Person
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
            Console.WriteLine($"Name: {Name}, Age: {Age}");
        }
    }

    class Program
    {
        static void Main()
        {
            // Create an object of Person class
            Person person = new Person("John", 30);

            // Call the method
            person.DisplayInfo();
        }
    }
}