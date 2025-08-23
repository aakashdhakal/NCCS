package Lab6;

class EvenThread extends Thread {
    public void run() {
        System.out.print("Even: ");
        for (int i = 2; i <= 20; i += 2)
            System.out.print(i + " ");
        System.out.println();
        try {
            Thread.sleep(100); // Small delay for better output readability
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

class OddThread extends Thread {
    public void run() {
        System.out.print("Odd: ");
        for (int i = 1; i <= 19; i += 2)
            System.out.print(i + " ");
        System.out.println();
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
            evenThread.join();
            oddThread.start();
            oddThread.join();
        } catch (Exception e) {
            System.out.println(e);
        }
        System.out.println("Finished printing even and odd numbers.");
    }
}