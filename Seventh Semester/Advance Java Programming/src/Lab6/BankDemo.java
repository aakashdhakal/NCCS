package Lab6;

class BankAccount {
    private int balance = 0;

    public synchronized void deposit(int amount, String name) {
        balance += amount;
        System.out.println(name + " deposited " + amount + ", Balance: " + balance);
    }

    public synchronized void withdraw(int amount, String name) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println(name + " withdrew " + amount + ", Balance: " + balance);
        } else {
            System.out.println(name + " tried to withdraw " + amount + " but insufficient balance: " + balance);
        }
    }
}

class DepositThread extends Thread {
    private BankAccount account;
    private int amount;

    public DepositThread(BankAccount acc, int amt, String name) {
        super(name);
        account = acc;
        amount = amt;
    }

    public void run() {
        account.deposit(amount, getName());
    }
}

class WithdrawThread extends Thread {
    private BankAccount account;
    private int amount;

    public WithdrawThread(BankAccount acc, int amt, String name) {
        super(name);
        account = acc;
        amount = amt;
    }

    public void run() {
        account.withdraw(amount, getName());
    }
}

public class BankDemo {
    public static void main(String[] args) {
        BankAccount acc = new BankAccount();
        Thread t1 = new DepositThread(acc, 1000, "Depositor-1");
        Thread t2 = new WithdrawThread(acc, 500, "Withdrawer-1");
        Thread t3 = new WithdrawThread(acc, 700, "Withdrawer-2");
        Thread t4 = new DepositThread(acc, 300, "Depositor-2");

        t1.start();
        t2.start();
        t3.start();
        t4.start();
    }
}