package com.company;

import java.util.Scanner;

public class P1 {
    public static void main(String[] args) {
        Scanner userInput = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Enter character");

        String choice = userInput.nextLine();  // Read user input

        if ((choice.charAt(0) == 'A') || (choice.charAt(0) == 'a'))
            System.out.println("Action movie fan\n");
        else if ((choice.charAt(0) == 'C') || (choice.charAt(0) == 'c'))
            System.out.println("Comedy movie fan\n");
        else if ((choice.charAt(0) == 'D') || (choice.charAt(0) == 'd'))
            System.out.println("Drama movie fan\n");
        else
            System.out.println("Invalid choice\n");
    }
}
