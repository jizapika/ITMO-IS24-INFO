package java.lab1.Tools.CentralBankTools;

import java.lab1.Exceptions.BankException;
import java.lab1.Tools.Accounts.*;
import java.lab1.Tools.BankDate;
import java.lab1.Tools.BankSettings.*;
import java.lab1.Tools.BankSettings.BankAccountsSettings.*;
import java.lab1.Tools.Banks.Bank;
import java.lab1.Tools.ClientPart.ClientList;
import java.lab1.Tools.Transactions.*;
import java.util.List;

public class CentralBank {
    private BankDate currentDay;
    private AllBanks banks;
    private AllClients clients;
    private AllAccounts accounts;
    private AllTransactions transactions;
    public CentralBank() throws BankException {
        banks = new AllBanks();
        clients = new AllClients();
        accounts = new AllAccounts();
        transactions = new AllTransactions();
        currentDay = new BankDate(0);
    }

    public List<Bank> allBanks() {
        return banks.immutableBanks();
    }

    public int addBank_ReturnID(BankSettings settings, String name) throws BankException {
        return banks.addBank_ReturnID(settings, name);
    }

    public int addClient_ReturnID(int bankId, String name, String surname) throws BankException {
        return clients.addClient_ReturnID(banks.findBank(bankId), name, surname);
    }

    public int addCreditAccount_ReturnID(int clientId) throws BankException {
        return accounts.addCreditAccount_ReturnID(
                clients.findClient(clientId).getBank().getSettings().getCreditSettings(),
                clients.findClient(clientId),
                currentDay);
    }

    public int addDebitAccount_ReturnID(int clientId) throws BankException {
        return accounts.addDebitAccount_ReturnID(
                clients.findClient(clientId).getBank().getSettings().getDebitSettings(),
                clients.findClient(clientId),
                currentDay);
    }

    public int addDepositAccount_ReturnID(int clientId) throws BankException {
        return accounts.addDepositAccount_ReturnID(
                clients.findClient(clientId).getBank().getSettings().getDepositSettings(),
                clients.findClient(clientId), currentDay);
    }

    public int addWithdrawal_ReturnID(int accountId, double sum) throws BankException {
        return transactions.addWithdrawalTransaction_ReturnID(accounts.findAccount(accountId), sum);
    }

    public int addReplenishment_ReturnID(int accountId, double sum) throws BankException {
        return transactions.addReplenishmentTransaction_ReturnID(accounts.findAccount(accountId), sum);
    }

    public int addTranslation_ReturnID(int fromAccountId, int toAccountId, double sum) throws BankException {
        return transactions.addTranslationTransaction_ReturnID(
                accounts.findAccount(fromAccountId), accounts.findAccount(toAccountId), sum);
    }

    public void makeNewWithdrawal(int accountId, double sum) throws BankException {
        makeTransactionById(addWithdrawal_ReturnID(accountId, sum));
    }

    public void makeNewReplenishment(int accountId, double sum) throws BankException {
        makeTransactionById(addReplenishment_ReturnID(accountId, sum));
    }

    public void makeNewTranslation(int fromAccountId, int toAccountId, double sum) throws BankException {
        makeTransactionById(addTranslation_ReturnID(fromAccountId, toAccountId, sum));
    }

    public void makeTransactionById(int transactionId) throws BankException {
        transactions.findTransaction(transactionId).makeIt();
    }

    public void addDays(int days) throws BankException {
        for (int d = 0; d < days; d++) waitOneDay();
    }

    public boolean isCorrectBankId(int bankId) {
        return banks.isCorrectBankId(bankId);
    }

    public boolean isCorrectClientId(int clientId) {
        return clients.isCorrectClientId(clientId);
    }

    public boolean isCorrectAccountId(int accountId) {
        return accounts.isCorrectAccountId(accountId);
    }

    public boolean isCorrectTransactionId(int transactionId) {
        return transactions.isCorrectTransactionId(transactionId);
    }

    public void renameBank(int bankId, String newName) throws BankException {
        banks.renameBank(bankId, newName);
    }

    public void renameClient(int clientId, String newName) throws BankException {
        clients.renameClient(clientId, newName);
    }

    public void resurnameClient(int clientId, String newSurname) throws BankException {
        clients.resurnameClient(clientId, newSurname);
    }

    public void repassportClient(int clientId, String newPassport) throws BankException {
        clients.repassportClient(clientId, newPassport);
    }

    public void readdressClient(int clientId, String newAddress) throws BankException {
        clients.readdressClient(clientId, newAddress);
    }

    public void blockClient(int clientId) throws BankException {
        clients.blockClient(clientId, accounts, transactions);
    }

    public String bankName(int bankId) throws BankException {
        return banks.findBank(bankId).name;
    }

    public String clientName(int clientId) throws BankException {
        return clients.findClient(clientId).name;
    }

    public String clientSurname(int clientId) throws BankException {
        return clients.findClient(clientId).surname;
    }

    public String clientPassport(int clientId) throws BankException {
        return clients.findClient(clientId).passport;
    }

    public String clientAddress(int clientId) throws BankException {
        return clients.findClient(clientId).address;
    }

    public boolean isClientApproved(int clientId) throws BankException {
        return clients.findClient(clientId).isApproved();
    }

    public AccountType accountType(int accountId) throws BankException {
        return accounts.findAccount(accountId).type();
    }

    public double accountSum(int accountId) throws BankException {
        return accounts.findAccount(accountId).getSum();
    }

    public TransactionType transactionType(int transactionId) throws BankException {
        return transactions.findTransaction(transactionId).type();
    }

    public double transactionAmmount(int transactionId) throws BankException {
        return transactions.findTransaction(transactionId).getAmount();
    }

    public ClientList bankClients(int bankId) throws BankException {
        return banks.findBank(bankId).bankClients(clients);
    }

    public AccountList clientAccounts(int clientId) throws BankException {
        return clients.findClient(clientId).clientAccounts(accounts);
    }

    public TransactionList accountTransactions(int accountId) throws BankException {
        return accounts.findAccount(accountId).accountTransactions(transactions);
    }

    public CreditAccountSettings getCreditAccountSettingsByBankId(int bankId) throws BankException {
        return banks.findBank(bankId).getSettings().getCreditSettings();
    }

    public DebitAccountSettings getDebitAccountSettingsByBankId(int bankId) throws BankException {
        return banks.findBank(bankId).getSettings().getDebitSettings();
    }

    public DepositAccountSettings getDepositAccountSettingsByBankId(int bankId) throws BankException {
        return banks.findBank(bankId).getSettings().getDepositSettings();
    }

    private void waitOneDay() throws BankException {
        currentDay = new BankDate(currentDay.getDate() + 1);
        accounts.waitDay(currentDay);
    }
}