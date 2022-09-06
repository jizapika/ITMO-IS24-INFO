package java.lab1.Tools.Transactions;

import java.lab1.Exceptions.BankException;

public abstract class Transaction {
    private double amount;
    private int id;

    public double getAmount() {
        return amount;
    }

    public int getId() {
        return id;
    }

    protected void setAmount(double amount) {
        this.amount = amount;
    }

    protected void setId(int id) {
        this.id = id;
    }
    public abstract void makeIt() throws BankException;
    public abstract void cancelIt();
    public abstract boolean isAccountId(int id);
    public abstract TransactionType type();
}
