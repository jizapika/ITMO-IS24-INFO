package java.lab1.Tools.Transactions;

import java.lab1.Exceptions.BankException;
import java.lab1.Tools.Accounts.Account;

public class WithdrawalTransaction extends Transaction {
    private Account from;
    private boolean isCompleted;

    public WithdrawalTransaction(Account from, int id, double sum)
    {
        isCompleted = false;
        this.from = from;
        setId(id);
        setAmount(sum);
    }

    @Override
    public void makeIt() throws BankException {
        if (isCompleted) return;
        isCompleted = true;
        from.makeWithdrawal(getAmount());
    }

    @Override
    public void cancelIt() {
        if (!isCompleted) return;
        isCompleted = false;
        from.cancelMakeWithdrawal(getAmount());
    }

    @Override
    public boolean isAccountId(int id) {
        return from.getId() == id;
    }

    @Override
    public TransactionType type() {
        return TransactionType.Withdrawal;
    }
}
