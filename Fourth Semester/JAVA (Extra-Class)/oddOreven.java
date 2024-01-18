
//java program to find whether a number is odd or even
import java.util.Scanner;

public class oddOreven {
    static int num;

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number: ");
        num = sc.nextInt();
        sc.close();
        check();
    }

    static void check() {
        if (num % 2 == 0) {
            System.out.println("The number is even");
        } else {
            System.out.println("The number is odd");
        }
    }
}
