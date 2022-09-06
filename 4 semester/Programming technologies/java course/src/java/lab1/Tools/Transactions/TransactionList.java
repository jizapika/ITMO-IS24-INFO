package java.lab1.Tools.Transactions;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class TransactionList {
    private List<Transaction> transactions;
    public TransactionList()
    {
        transactions = new ArrayList<Transaction>();
    }

    public List<Transaction> immutableTransactions() {
        return Collections.unmodifiableList(transactions);
    }

    public void addTransaction(Transaction transaction)
    {
        if (transaction != null)
            transactions.add(transaction);
    }
}
