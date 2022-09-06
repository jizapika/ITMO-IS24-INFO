package java.lab1.Tools.Banks;

import java.lab1.Exceptions.BankException;
import java.lab1.Tools.BankSettings.BankSettings;
import java.lab1.Tools.CentralBankTools.AllClients;
import java.lab1.Tools.ClientPart.Client;
import java.lab1.Tools.ClientPart.ClientList;

public class Bank {

    private BankSettings settings;
    public String name;
    private int id;

    public Bank(BankSettings bankSettings, String name, int id) throws BankException {
        this.settings = bankSettings;
        this.name = name;
        if (id < 0) throw new BankException("Negative value passed.");
        this.id = id;
    }

    public BankSettings getSettings() {
        return settings;
    }

    public int getId() {
        return id;
    }

    public ClientList bankClients(AllClients allClients)
    {
        var clients = new ClientList();
        for (Client client : allClients.immutableClients())
            if (client.isBankId(id)) clients.addClient(client);

        return clients;
    }
}
