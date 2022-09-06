package java.lab1.Tools.BankSettings.BuildingAccountsProperties;

import java.lab1.Exceptions.BankException;

public class CommissionLimitForDepositAccount {

    private double maxSum;
    private double percentMonthCommission;
    public CommissionLimitForDepositAccount nextObject;

    public CommissionLimitForDepositAccount(
            double maxSum,
            double monthCommission)
    {
        nextObject = null;
        this.maxSum = maxSum;
        this.percentMonthCommission = monthCommission;
    }

    public double getMaxSum() {
        return maxSum;
    }

    public double getPercentMonthCommission() {
        return percentMonthCommission;
    }

    public double monthCommission(double currentAccountSum) throws BankException {
        if (nextObject != null)
            return currentAccountSum > maxSum
                    ? nextObject.monthCommission(currentAccountSum)
                    : percentMonthCommission;
        else
            throw new BankException("This sum is very big for this account.");
    }
}
