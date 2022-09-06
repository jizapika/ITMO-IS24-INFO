package java.lab1.Services.UI;

import java.util.Scanner;

public class ConsoleUserInterface implements IUserInterface {

    @Override
    public String writeAndRead(String message) {
        write(message);
        Scanner input = new Scanner(System.in);
        return input.nextLine();
    }

    @Override
    public void write(String message) {
        System.out.println(message);
    }
}
