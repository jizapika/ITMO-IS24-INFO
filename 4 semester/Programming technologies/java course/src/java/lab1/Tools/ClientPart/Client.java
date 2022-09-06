package java.lab1.Tools.ClientPart;

import java.lab1.Tools.Accounts.Account;
import java.lab1.Tools.Accounts.AccountList;
import java.lab1.Tools.Banks.Bank;
import java.lab1.Tools.CentralBankTools.AllAccounts;
import java.lab1.Tools.CentralBankTools.AllTransactions;
import java.lab1.Tools.Transactions.Transaction;
import java.lab1.Tools.Transactions.TransactionList;

public class Client {
    private boolean isBlocked;
    private Bank bank;
    private int id;
    public String name;
    public String surname;
    public String passport;
    public String address;

    public Client(Bank bank, int id, String name, String surname)
    {
        this.bank = bank;
        isBlocked = false;
        this.id = id;
        this.name = name;
        this.surname = surname;
    }

    public Bank getBank() {
        return bank;
    }

    public int getId() {
        return id;
    }

    public boolean isApproved() {
            return !(isBlocked || passport == null || passport == "" || address == null || address == "");
    }

    public AccountList clientAccounts(AllAccounts allAccounts)
    {
        AccountList accounts = new AccountList();
        for (Account account : allAccounts.immutableAccounts())
        if (account.isClientId(id)) accounts.addAccount(account);

        return accounts;
    }

    public boolean isBankId(int id) {
        return bank.getId() == id;
    }

    public void blockHim(AllAccounts allAccounts, AllTransactions allTransactions)
    {
        if (!isBlocked)
            return;
        cancelAllTransaction(allAccounts, allTransactions);
        isBlocked = true;
    }

    private void cancelAllTransaction(AllAccounts allAccounts, AllTransactions allTransactions)
    {
        AccountList accounts = clientAccounts(allAccounts);
        for (Account account : accounts.immutableAccounts())
        {
            TransactionList transactions = account.accountTransactions(allTransactions);
            for (Transaction transaction : transactions.immutableTransactions())
            {
                transaction.cancelIt();
            }
        }
    }
}
