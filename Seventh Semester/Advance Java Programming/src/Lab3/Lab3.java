package Lab3;

// Shape interface with getArea method
interface Shape {
    double getArea();
}

// Rectangle class implementing Shape
class Rectangle implements Shape {
    private double length;
    private double width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public double getArea() {
        return length * width;
    }
}

// Circle class implementing Shape
class Circle implements Shape {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }
}

// Triangle class implementing Shape
class Triangle implements Shape {
    private double base;
    private double height;

    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    @Override
    public double getArea() {
        return 0.5 * base * height;
    }
}

// Test class to demonstrate functionality
public class Lab3 {
    public static void main(String[] args) {
        Shape rectangle = new Rectangle(21, 13);
        Shape circle = new Circle(17);
        Shape triangle = new Triangle(25, 9);

        System.out.println("Rectangle area: " + rectangle.getArea());
        System.out.println("Circle area: " + circle.getArea());
        System.out.println("Triangle area: " + triangle.getArea());
    }
}