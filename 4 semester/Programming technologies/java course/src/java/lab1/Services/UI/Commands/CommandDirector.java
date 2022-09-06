package java.lab1.Services.UI.Commands;

import java.lab1.Services.UI.IUserInterface;

public class CommandDirector {
    private IUserInterface userInterface;

    public CommandDirector(IUserInterface userInterface)
    {
        this.userInterface = userInterface;
    }

    public ICommand getCommand(String command)
    {
        switch (firstWord(command))
        {
            case "create":
                return createDirector(deleteFirstWord(command));
            case "make":
                return makeDirector(deleteFirstWord(command));
            case "print":
                return printDirector(deleteFirstWord(command));
            case "set":
                return SetDirector(deleteFirstWord(command));
            case "wait":
                return WaitDirector(deleteFirstWord(command));
            case "quit":
                return new QuitCommand(userInterface);
            case "?":
                return new HelpCommand(userInterface);
            default:
                return new UnknownCommand(userInterface);
        }
    }

    private String firstWord(String command)
    {
        return command.split(" ")[0];
    }

    private String deleteFirstWord(String command)
    {
        String[] line = command.split(" ");
        String returnCommand = "";
        for (int i = 1; i < line.length; i++)
        {
            returnCommand = returnCommand + " " + line[i];
        }

        return returnCommand;
    }

    private int howManyWords(String command)
    {
        return command.split(" ").length;
    }

    private ICommand createDirector(String command)
    {
        if (howManyWords(command) == 0)
            command = userInterface.writeAndRead("What do you want to create?");

        switch (firstWord(command))
        {
            case "account":
                return new CreateAccount(userInterface);
            default:
                return new UnknownCommand(userInterface);
        }
    }

    private ICommand makeDirector(String command)
    {
        if (howManyWords(command) == 0)
            command = userInterface.writeAndRead("What do you want to make?");

        switch (firstWord(command))
        {
            case "replenishment":
                return new MakeReplenishment(userInterface);
            case "translation":
                return new MakeTranslation(userInterface);
            case "withdrawal":
                return new MakeWithdrawal(userInterface);
            default:
                return new UnknownCommand(userInterface);
        }
    }

    private ICommand printDirector(String command)
    {
        if (howManyWords(command) == 0)
            command = userInterface.writeAndRead("What do you want to print?");

        switch (firstWord(command))
        {
            case "users":
                return new PrintClients(userInterface);
            case "accounts":
                return new PrintAccounts(userInterface);
            case "transactions":
                return new PrintTransactions(userInterface);
            case "settings":
                return new PrintBankSettings(userInterface);
            case "concrete":
                return PrintConcreteDirector(DeleteFirstWord(command));
            default:
                return new UnknownCommand(userInterface);
        }
    }

}
