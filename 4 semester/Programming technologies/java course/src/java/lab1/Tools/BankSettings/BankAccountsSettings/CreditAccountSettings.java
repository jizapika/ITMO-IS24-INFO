package java.lab1.Tools.BankSettings.BankAccountsSettings;

import java.lab1.Exceptions.BankException;

public class CreditAccountSettings {
    private double dailySumCommission;
    public double lowerLimit;
    public CreditAccountSettings(double lowerLimit, double dailySumCommission) throws BankException {
        if (lowerLimit >= 0)
            throw new BankException("Lower limit for credit account need to be negative.");
        this.lowerLimit = lowerLimit;
        this.dailySumCommission = dailySumCommission;
    }

    public double getLowerLimit() {
        return lowerLimit;
    }

    public double dailySumCommission(double currentAccountSum) {
        return dailySumCommission;
    }
}
