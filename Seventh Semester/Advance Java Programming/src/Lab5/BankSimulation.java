package Lab5;

class BankAccount {
    private int balance;

    public BankAccount(int initialBalance) {
        this.balance = initialBalance;
    }

    // Synchronized withdraw method
    public synchronized void withdraw(int amount, String threadName) {
        if (balance >= amount) {
            System.out.println(threadName + " is withdrawing " + amount);
            balance -= amount;
            System.out.println("Balance after " + threadName + " withdraw: " + balance);
        } else {
            System.out.println(threadName + " cannot withdraw " + amount + ". Insufficient balance: " + balance);
        }
    }
}

class WithdrawThread extends Thread {
    private BankAccount account;
    private int amount;

    public WithdrawThread(BankAccount account, int amount, String name) {
        super(name);
        this.account = account;
        this.amount = amount;
    }

    public void run() {
        account.withdraw(amount, getName());
    }
}

public class BankSimulation {
    public static void main(String[] args) {
        BankAccount account = new BankAccount(1000);

        Thread t1 = new WithdrawThread(account, 700, "Thread-1");
        Thread t2 = new WithdrawThread(account, 500, "Thread-2");
        Thread t3 = new WithdrawThread(account, 300, "Thread-3");

        t1.start();
        t2.start();
        t3.start();
    }
}