package java.lab1.Tools.Accounts;

import java.lab1.Exceptions.BankException;
import java.lab1.Tools.BankDate;
import java.lab1.Tools.BankSettings.BankAccountsSettings.DebitAccountSettings;
import java.lab1.Tools.CentralBankTools.AllTransactions;
import java.lab1.Tools.ClientPart.Client;
import java.lab1.Tools.Transactions.Transaction;
import java.lab1.Tools.Transactions.TransactionList;

public class DebitAccount extends Account {

    private Client client;
    private DebitAccountSettings settings;
    private BankDate dateOfCreation;
    private double accumulatedSum;

    public DebitAccount(
            Client client,
            DebitAccountSettings settings,
            int id,
            BankDate dateOfCreation) throws BankException {
        this.client = client;
        this.settings = settings;
        this.dateOfCreation = dateOfCreation;
        this.accumulatedSum = 0;
        setSum(0);
        setId(id);
    }

    @Override
    public void makeWithdrawal(double withdrawalSum) throws BankException {
        double sum = getSum();
        if (!client.isApproved())
            throw new BankException("Client isn't approved and cannot make a withdrawal.");
        if (withdrawalSum > sum)
            throw new BankException("Debit account doesn't have enough money for the transaction.");
        setSum(sum - withdrawalSum);
    }

    @Override
    public void makeReplenishment(double replenishmentSum) {
        setSum(getSum() + replenishmentSum);
    }

    @Override
    public void makeTranslationTo(Account otherAccount, double translationSum) throws BankException {
        double sum = getSum();
        if (!client.isApproved())
            throw new BankException("Client isn't approved and cannot make a translation.");
        if (translationSum > sum)
            throw new BankException("Debit account doesn't have enough money for the transaction.");
        otherAccount.translationFrom(translationSum);
        setSum(sum - translationSum);
    }

    @Override
    public void translationFrom(double translationSum) {
        setSum(getSum() + translationSum);
    }

    @Override
    public TransactionList accountTransactions(AllTransactions allTransactions) {
        TransactionList transactions = new TransactionList();
        for (Transaction transaction : allTransactions.immutableTransactions())
            if (transaction.isAccountId(this.getId())) transactions.addTransaction(transaction);
        return transactions;
    }

    @Override
    public void waitDay(BankDate currentDate) throws BankException {
        double sum = getSum();
        int daysOnMonth = 30;
        accumulatedSum += settings.monthlyPercentCommission(sum) / daysOnMonth * sum;
        if (currentDate.getDate() < dateOfCreation.getDate()) throw new BankException("Not correct date passed.");
        if ((currentDate.getDate() - dateOfCreation.getDate()) % daysOnMonth != 0) return;
        setSum(sum + accumulatedSum);
        accumulatedSum = 0;
    }

    @Override
    public boolean isClientId(int id) {
        return client.getId() == id;
    }

    @Override
    public AccountType type() {
        return AccountType.Debit;
    }
}
