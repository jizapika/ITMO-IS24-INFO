package java.lab1.Tools.BankSettings.BankAccountsSettings;

import java.lab1.Exceptions.BankException;
import java.lab1.Tools.BankSettings.BuildingAccountsProperties.CommissionLimitForDepositAccount;
import java.util.*;

public class DepositAccountSettings {
    private double _currentMax;

    private int daysDuration;

    private List<CommissionLimitForDepositAccount> commissionsSettings;

    public DepositAccountSettings(int daysDuration) throws BankException {
        _currentMax = 0;
        commissionsSettings = new ArrayList<CommissionLimitForDepositAccount>();
        if (daysDuration < 0) throw new BankException("Passed a negative value.");
        this.daysDuration = daysDuration;
    }

    public int getDaysDuration() {
        return daysDuration;
    }

    public void addCommissionLimit(double raisedBorder, double newCommission) throws BankException {
        if (_currentMax >= raisedBorder)
        {
            throw new BankException("Small border");
        }

        var commissionLimitForDepositAccount = new CommissionLimitForDepositAccount(raisedBorder, newCommission);
        _currentMax = raisedBorder;
        if (commissionsSettings.size() > 0)
            commissionsSettings.get(commissionsSettings.size() - 1).nextObject = commissionLimitForDepositAccount;
        commissionsSettings.add(commissionLimitForDepositAccount);
    }

    public double monthlyPercentCommission(double currentAccountSum) throws BankException {
        if (commissionsSettings.size() == 0)
            throw new BankException("DepositSettings aren't.");
        return commissionsSettings.get(0).monthCommission(currentAccountSum);
    }
}
