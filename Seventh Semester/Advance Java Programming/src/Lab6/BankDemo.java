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
        BankAccount account = new BankAccount();

        Thread depositor1 = new Thread(() -> account.deposit(2000, "Depositor1"));
        Thread withdrawer1 = new Thread(() -> account.withdraw(1200, "Withdrawer1"));
        Thread depositor2 = new Thread(() -> account.deposit(1000, "Depositor2"));
        Thread withdrawer2 = new Thread(() -> account.withdraw(1500, "Withdrawer2"));
        Thread depositor3 = new Thread(() -> account.deposit(2500, "Depositor3"));
        Thread withdrawer3 = new Thread(() -> account.withdraw(1800, "Withdrawer3"));
        Thread depositor4 = new Thread(() -> account.deposit(1000, "Depositor4"));
        Thread withdrawer4 = new Thread(() -> account.withdraw(2200, "Withdrawer4"));

        depositor1.start();
        withdrawer1.start();
        depositor2.start();
        withdrawer2.start();
        depositor3.start();
        withdrawer3.start();
        depositor4.start();
        withdrawer4.start();
    }
}