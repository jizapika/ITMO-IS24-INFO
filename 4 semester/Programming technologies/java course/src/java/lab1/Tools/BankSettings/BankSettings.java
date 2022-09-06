package java.lab1.Tools.BankSettings;

import java.lab1.Tools.BankSettings.BankAccountsSettings.*;

public class BankSettings {

    public CreditAccountSettings creditSettings;
    public DebitAccountSettings debitSettings;
    public DepositAccountSettings depositSettings;

    public BankSettings(
            CreditAccountSettings creditSettings,
            DebitAccountSettings debitSettings,
            DepositAccountSettings depositSettings) {
        this.creditSettings = creditSettings;
        this.debitSettings = debitSettings;
        this.depositSettings = depositSettings;
    }

    public CreditAccountSettings getCreditSettings() {
        return creditSettings;
    }

    public DebitAccountSettings getDebitSettings() {
        return debitSettings;
    }

    public DepositAccountSettings getDepositSettings() {
        return depositSettings;
    }
}