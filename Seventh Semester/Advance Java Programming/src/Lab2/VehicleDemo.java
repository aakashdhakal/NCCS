package Lab2;

// Base class
abstract class Vehicle {
    protected String make, model, fuelType;
    protected int year;

    public Vehicle(String make, String model, int year, String fuelType) {
        this.make = make;
        this.model = model;
        this.year = year;
        this.fuelType = fuelType;
    }

    public abstract double fuelEfficiency(); // km per liter

    public abstract double maxSpeed(); // km/h

    public double distanceTraveled(double fuel) {
        return fuel * fuelEfficiency();
    }

    public void showInfo() {
        System.out.println(
                getClass().getSimpleName() + " - " + make + " " + model + " (" + year + "), Fuel: " + fuelType);
    }
}

class Truck extends Vehicle {
    public Truck(String make, String model, int year, String fuelType) {
        super(make, model, year, fuelType);
    }

    @Override
    public double fuelEfficiency() {
        return 5.0;
    }

    @Override
    public double maxSpeed() {
        return 120.0;
    }
}

class Car extends Vehicle {
    public Car(String make, String model, int year, String fuelType) {
        super(make, model, year, fuelType);
    }

    @Override
    public double fuelEfficiency() {
        return 15.0;
    }

    @Override
    public double maxSpeed() {
        return 180.0;
    }
}

class Motorcycle extends Vehicle {
    public Motorcycle(String make, String model, int year, String fuelType) {
        super(make, model, year, fuelType);
    }

    @Override
    public double fuelEfficiency() {
        return 35.0;
    }

    @Override
    public double maxSpeed() {
        return 140.0;
    }
}

public class VehicleDemo {
    public static void main(String[] args) {
        Vehicle[] vehicles = { new Truck("Tata", "LPT", 2020, "Diesel"), new Car("Toyota", "Corolla", 2022, "Petrol"),
                new Motorcycle("Honda", "CBR", 2021, "Petrol") };

        for (Vehicle v : vehicles) {
            v.showInfo();
            System.out.println("  Fuel Efficiency: " + v.fuelEfficiency() + " km/l");
            System.out.println("  Max Speed: " + v.maxSpeed() + " km/h");
            System.out.println("  Distance with 10L fuel: " + v.distanceTraveled(10) + " km\n");
        }
    }
}