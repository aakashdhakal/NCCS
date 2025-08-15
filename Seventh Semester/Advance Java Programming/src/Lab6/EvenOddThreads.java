package Lab6;

class EvenThread extends Thread {
    public void run() {
        for (int i = 2; i <= 20; i += 2)
            System.out.println("Even: " + i);
        try {
            Thread.sleep(100); // Small delay for better output readability
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

class OddThread extends Thread {
    public void run() {
        for (int i = 1; i <= 19; i += 2)
            System.out.println("Odd: " + i);
        try {
            Thread.sleep(100); // Small delay for better output readability
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

public class EvenOddThreads {
    public static void main(String[] args) {
        Thread evenThread = new EvenThread();
        Thread oddThread = new OddThread();
        try {
            evenThread.start();
            oddThread.start();
        } catch (Exception e) {
            System.out.println(e);
        }
        System.out.println("Finished printing even and odd numbers.");
    }
}