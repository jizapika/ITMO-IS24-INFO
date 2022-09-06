package java.lab1.Tools.ClientPart;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ClientList {
    private List<Client> clients;

    public ClientList()
    {
        clients = new ArrayList<Client>();
    }

    public List<Client> immutableClients() {
        return Collections.unmodifiableList(clients);
    }

    public void addClient(Client client)
    {
        clients.add(client);
    }
}
