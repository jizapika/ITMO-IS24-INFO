package java.lab1.Tools;

import java.lab1.Exceptions.BankException;

public class BankDate {
    private int date = 0;

    public BankDate(int date) throws BankException {
        if (date < 0) throw new BankException("Negative date passed.");
        this.date = date;
    }

    public int getDate() {
        return date;
    }
}
