package java.lab1.Tools.Accounts;

import java.lab1.Exceptions.BankException;
import java.lab1.Tools.BankDate;
import java.lab1.Tools.CentralBankTools.AllTransactions;
import java.lab1.Tools.Transactions.TransactionList;

public abstract class Account {
    private double sum;
    private int id;

    public double getSum() {
        return sum;
    }

    public int getId() {
        return this.id;
    }

    protected void setSum(double sum) {
        this.sum = sum;
    }

    protected void setId(int id) throws BankException {
        if (id < 0) throw new BankException("Negative id passed.");
        this.id = id;
    }

    public abstract void makeWithdrawal(double withdrawalSum) throws BankException;
    public abstract void makeReplenishment(double replenishmentSum);
    public abstract void makeTranslationTo(Account otherAccount, double translationSum) throws BankException;
    public abstract void translationFrom(double translationSum);

    public void cancelMakeWithdrawal(double withdrawalSum)
    {
        sum += withdrawalSum;
    }

    public void cancelMakeReplenishment(double replenishmentSum)
    {
        sum -= replenishmentSum;
    }

    public void cancelMakeTranslationTo(Account otherAccount, double translationSum)
    {
        otherAccount.cancelTranslationFrom(translationSum);
        sum += translationSum;
    }

    public void cancelTranslationFrom(double translationSum)
    {
        sum -= translationSum;
    }

    public abstract TransactionList accountTransactions(AllTransactions allTransactions);
    public abstract void waitDay(BankDate currentDate) throws BankException;
    public abstract boolean isClientId(int id);
    public abstract AccountType type();
}
