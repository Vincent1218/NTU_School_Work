package com.company;
import java.util.Scanner;

public class MyFirstProgram {
    public static void main(String[] args) {
        Scanner userInput = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Enter username");

        String userName = userInput.nextLine();  // Read user input
        System.out.println("Username is: " + userName);  // Output user input
    }
}
