package java.lab1.Tools.CentralBankTools;

import java.lab1.Exceptions.BankException;
import java.lab1.Tools.Accounts.*;
import java.lab1.Tools.BankDate;
import java.lab1.Tools.BankSettings.BankAccountsSettings.*;
import java.lab1.Tools.ClientPart.Client;
import java.util.*;

public class AllAccounts {
    private List<Account> accounts;
    private int currentNumberId = 1;

    public AllAccounts()
    {
        accounts = new ArrayList<Account>();
    }

    public List<Account> immutableAccounts() {
        return Collections.unmodifiableList(accounts);
    }

    public int addCreditAccount_ReturnID(CreditAccountSettings settings, Client client, BankDate dateOfCreation)
            throws BankException {
        CreditAccount account = new CreditAccount(client, settings, currentNumberId, dateOfCreation);
        accounts.add(account);
        currentNumberId++;
        return account.getId();
    }

    public int addDebitAccount_ReturnID(DebitAccountSettings settings, Client client, BankDate dateOfCreation)
            throws BankException {
        DebitAccount account = new DebitAccount(client, settings, currentNumberId, dateOfCreation);
        accounts.add(account);
        currentNumberId++;
        return account.getId();
    }

    public int addDepositAccount_ReturnID(DepositAccountSettings settings, Client client, BankDate dateOfCreation)
            throws BankException {
        DepositAccount account = new DepositAccount(client, settings, dateOfCreation, currentNumberId);
        accounts.add(account);
        currentNumberId++;
        return account.getId();
    }

    public Account findAccount(int id) throws BankException {
        for (Account account : accounts) {
            if (account.getId() == id) return account;
        }
        throw new BankException("Account doesn't exist.");
    }

    public void waitDay(BankDate currentDay) throws BankException {
        for (Account account : accounts)
        {
            account.waitDay(currentDay);
        }
    }

    public boolean isCorrectAccountId(int accountId) {
        for (Account account : accounts) {
            if (account.getId() == accountId) return true;
        }
        return false;
    }
}
