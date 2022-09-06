package java.lab1.Tools.Accounts;

import java.lab1.Exceptions.BankException;
import java.lab1.Tools.BankDate;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class AccountList {
    private List<Account> accounts;
    public AccountList()
    {
        accounts = new LinkedList<Account>();
    }

    public List<Account> immutableAccounts() {
        return Collections.unmodifiableList(accounts);
    }

    public void addAccount(Account account) {
        if (account != null)
            accounts.add(account);
        immutableAccounts().add(account);
    }
}