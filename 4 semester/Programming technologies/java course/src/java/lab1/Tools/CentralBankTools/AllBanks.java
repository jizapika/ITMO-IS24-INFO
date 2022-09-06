package java.lab1.Tools.CentralBankTools;

import java.lab1.Exceptions.BankException;
import java.lab1.Tools.BankSettings.BankSettings;
import java.lab1.Tools.Banks.Bank;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class AllBanks {
    private List<Bank> banks;
    private int currentNumberId = 1;

    public AllBanks()
    {
        banks = new ArrayList<Bank>();
    }

    public List<Bank> immutableBanks() {
        return Collections.unmodifiableList(banks);
    }

    public int addBank_ReturnID(BankSettings bankSettings, String name) throws BankException {
        var bank = new Bank(bankSettings, name, currentNumberId);
        banks.add(bank);
        currentNumberId++;
        return bank.getId();
    }

    public Bank findBank(int id) throws BankException {
        for (Bank bank : banks) {
            if (bank.getId() == id) return bank;
        }
        throw new BankException("Bank doesn't exist.");
    }

    public void renameBank(int id, String newName) throws BankException {
        findBank(id).name = newName;
    }

    public boolean isCorrectBankId(int bankId) {
        for (Bank bank : banks) {
            if (bank.getId() == bankId) return true;
        }
        return false;
    }
}
