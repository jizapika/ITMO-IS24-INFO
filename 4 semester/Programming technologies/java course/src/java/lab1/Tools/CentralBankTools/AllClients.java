package java.lab1.Tools.CentralBankTools;

import java.lab1.Exceptions.BankException;
import java.lab1.Tools.Banks.Bank;
import java.lab1.Tools.ClientPart.Client;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class AllClients {
    private List<Client> clients;
    private int currentNumberId;

    public AllClients() {
        clients = new ArrayList<Client>();
        currentNumberId = 1;
    }

    public List<Client> immutableClients() {
        return Collections.unmodifiableList(clients);
    }

    public int addClient_ReturnID(Bank bank, String name, String surname) {
        var newClient = new Client(bank, currentNumberId, name, surname);
        currentNumberId++;
        clients.add(newClient);
        return newClient.getId();
    }

    public Client findClient(int id) throws BankException {
        for (Client client : clients) {
            if (client.getId() == id) return client;
        }
        throw new BankException("Client doesn't exist.");
    }

    public void renameClient(int id, String newName) throws BankException {
        findClient(id).name = newName;
    }

    public void resurnameClient(int id, String newSurname) throws BankException {
        findClient(id).surname = newSurname;
    }

    public void repassportClient(int id, String newPassport) throws BankException {
        findClient(id).passport = newPassport;
    }

    public void readdressClient(int id, String newAddress) throws BankException {
        findClient(id).address = newAddress;
    }

    public void blockClient(int id, AllAccounts accounts, AllTransactions transactions) throws BankException {
        findClient(id).blockHim(accounts, transactions);
    }

    public boolean isCorrectClientId(int clientId) {
        for (Client client : clients) {
            if (client.getId() == clientId) return true;
        }
        return false;
    }
}
