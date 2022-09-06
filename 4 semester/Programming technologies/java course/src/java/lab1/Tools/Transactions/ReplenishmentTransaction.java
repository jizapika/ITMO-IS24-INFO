package java.lab1.Tools.Transactions;

import java.lab1.Tools.Accounts.Account;

public class ReplenishmentTransaction extends Transaction {
    private Account to;
    private boolean isCompleted;

    public ReplenishmentTransaction(Account to, int id, double sum) {
        this.to = to;
        this.isCompleted = false;
        setId(id);
        setAmount(sum);
    }

    @Override
    public void makeIt() {
        if (isCompleted) return;
        isCompleted = true;
        to.makeReplenishment(this.getAmount());
    }

    @Override
    public void cancelIt()
    {
        if (!isCompleted) return;
        isCompleted = false;
        to.cancelMakeReplenishment(this.getAmount());
    }

    @Override
    public boolean isAccountId(int id) {
        return to.getId() == id;
    }

    @Override
    public TransactionType type() {
        return TransactionType.Replenishment;
    }
}
