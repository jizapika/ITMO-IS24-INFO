package java.lab1.Tools.Transactions;

import java.lab1.Exceptions.BankException;
import java.lab1.Tools.Accounts.Account;

public class TranslationTransaction extends Transaction {

    private Account from;
    private Account to;
    private boolean isCompleted;

    public TranslationTransaction(Account from, Account to, int id, double sum)
    {
        isCompleted = false;
        this.to = to;
        this.from = from;
        this.setId(id);
        setAmount(sum);
    }

    @Override
    public void makeIt() throws BankException {
        if (isCompleted) return;
        isCompleted = true;
        from.makeTranslationTo(to, getAmount());
    }

    @Override
    public void cancelIt() {

        if (!isCompleted) return;
        isCompleted = false;
        from.cancelMakeTranslationTo(to, getAmount());
    }

    @Override
    public boolean isAccountId(int id) {
        return to.getId() == id;
    }

    @Override
    public TransactionType type() {
        return TransactionType.Translation;
    }
}
