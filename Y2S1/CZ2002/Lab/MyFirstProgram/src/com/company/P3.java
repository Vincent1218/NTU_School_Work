package com.company;

import java.util.Scanner;

public class P3 {
    public static void main(String[] args) {
        Scanner userInput = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Starting: ");
        int start = userInput.nextInt();  // Read user input
        System.out.println("Ending: ");
        int end = userInput.nextInt();  // Read user input
        System.out.println("Increment: ");
        int incre = userInput.nextInt();  // Read user input

        System.out.println("US$          S$");
        System.out.println("_______________");

        if(end < start){
            System.out.println("Error input!!");
        }

        for ( int i = start ; i <= end ; i+=incre ){
            System.out.println(i+"___________"+(i*1.82));
        }

        System.out.println("Starting: ");
        int start1 = userInput.nextInt();  // Read user input
        System.out.println("Ending: ");
        int end1 = userInput.nextInt();  // Read user input
        System.out.println("Increment: ");
        int incre1 = userInput.nextInt();  // Read user input

        System.out.println("US$          S$");
        System.out.println("_______________");

        if(end1 < start1){
            System.out.println("Error input!!");
        }

        int x = start1;
        while(x <= end1 ){
            System.out.println(x+"___________"+(x*1.82));
            x+=incre1;
        }

        System.out.println("Starting: ");
        int start2 = userInput.nextInt();  // Read user input
        System.out.println("Ending: ");
        int end2 = userInput.nextInt();  // Read user input
        System.out.println("Increment: ");
        int incre2 = userInput.nextInt();  // Read user input

        System.out.println("US$          S$");
        System.out.println("_______________");

        int y = start2;
        do {
            if(end2 < start2){
                System.out.println("Error input!!");
                break;
            }
            System.out.println(y+"___________"+(y*1.82));
            y+=incre2;
        }
        while(y <= end2 );



    }
}
