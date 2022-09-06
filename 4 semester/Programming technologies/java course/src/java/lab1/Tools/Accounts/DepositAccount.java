package java.lab1.Tools.Accounts;

import java.lab1.Exceptions.BankException;
import java.lab1.Tools.BankDate;
import java.lab1.Tools.BankSettings.BankAccountsSettings.DepositAccountSettings;
import java.lab1.Tools.CentralBankTools.AllTransactions;
import java.lab1.Tools.ClientPart.Client;
import java.lab1.Tools.Transactions.Transaction;
import java.lab1.Tools.Transactions.TransactionList;

public class DepositAccount extends Account {
    private Client client;
    private DepositAccountSettings settings;
    private BankDate dateOfCreation;
    private double accumulatedSum;
    private BankDate currentDate;

    public DepositAccount(
            Client client,
            DepositAccountSettings settings,
            BankDate dateOfCreation,
            int id) throws BankException {
        this.client = client;
        this.settings = settings;
        this.dateOfCreation = dateOfCreation;
        this.accumulatedSum = 0;
        currentDate = dateOfCreation;
        setSum(0);
        setId(id);
    }

    @Override
    public void makeWithdrawal(double withdrawalSum) throws BankException {
        double sum = getSum();
        if (!client.isApproved())
            throw new BankException("Client isn't approved and cannot make a withdrawal.");
        if (currentDate.getDate() < dateOfCreation.getDate() + settings.getDaysDuration())
            throw new BankException("The deposit period isn't over yet");
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
        if (currentDate.getDate() < dateOfCreation.getDate() + settings.getDaysDuration())
            throw new BankException("The deposit period isn't over yet");
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
        if (currentDate.getDate() - dateOfCreation.getDate() > settings.getDaysDuration()) return;
        accumulatedSum += settings.monthlyPercentCommission(sum) / daysOnMonth * sum;
        if (currentDate.getDate() - dateOfCreation.getDate() == settings.getDaysDuration() ||
                (currentDate.getDate() - dateOfCreation.getDate()) % daysOnMonth == 0)
        {
            setSum(sum + accumulatedSum);
            accumulatedSum = 0;
        }

        this.currentDate = currentDate;
    }

    @Override
    public boolean isClientId(int id) {
        return client.getId() == id;
    }

    @Override
    public AccountType type() {
        return AccountType.Deposit;
    }
}
