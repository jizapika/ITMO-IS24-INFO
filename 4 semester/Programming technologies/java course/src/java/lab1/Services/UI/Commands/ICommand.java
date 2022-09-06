package java.lab1.Services.UI.Commands;

import java.lab1.Tools.CentralBankTools.CentralBank;

@FunctionalInterface
public interface ICommand {
    public boolean RunCommand(OutBooleanParameter shouldQuit, CentralBank centralBank);
}