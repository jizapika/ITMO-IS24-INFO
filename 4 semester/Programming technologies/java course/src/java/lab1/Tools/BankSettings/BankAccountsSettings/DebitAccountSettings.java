package java.lab1.Tools.BankSettings.BankAccountsSettings;

public class DebitAccountSettings {
    private final double monthlyCommission;

    public DebitAccountSettings(double commission) {
        monthlyCommission = commission;
    }

    public double monthlyPercentCommission(double currentAccountSum) {
        return monthlyCommission;
    }
}
