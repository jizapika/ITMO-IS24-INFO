package java.lab1.Tools.CentralBankTools;

import java.lab1.Exceptions.BankException;
import java.lab1.Tools.Accounts.Account;
import java.lab1.Tools.ClientPart.Client;
import java.lab1.Tools.Transactions.*;
import java.util.*;

public class AllTransactions {
    private List<Transaction> transactions;
    private int currentNumberId = 1;

    public AllTransactions()
    {
        transactions = new ArrayList<Transaction>();
    }

    public List<Transaction> immutableTransactions() {
        return Collections.unmodifiableList(transactions);
    }

    public int addWithdrawalTransaction_ReturnID(Account account, double sum)
    {
        var transaction = new WithdrawalTransaction(account, currentNumberId, sum);
        transactions.add(transaction);
        currentNumberId++;
        return transaction.getId();
    }

    public int addReplenishmentTransaction_ReturnID(Account account, double sum)
    {
        var transaction = new ReplenishmentTransaction(account, currentNumberId, sum);
        transactions.add(transaction);
        currentNumberId++;
        return transaction.getId();
    }

    public int addTranslationTransaction_ReturnID(Account from, Account to, double sum)
    {
        var transaction = new TranslationTransaction(from, to, currentNumberId, sum);
        transactions.add(transaction);
        currentNumberId++;
        return transaction.getId();
    }

    public Transaction findTransaction(int id) throws BankException {
        for (Transaction transaction : transactions) {
            if (transaction.getId() == id) return transaction;
        }

        throw new BankException("Client doesn't exist.");
    }

    public boolean isCorrectTransactionId(int transactionId) {
        for (Transaction transaction : transactions) {
            if (transaction.getId() == transactionId) return true;
        }

        return false;
    }
}
