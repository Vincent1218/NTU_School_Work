package com.company;

import java.util.Scanner;

public class P4 {
    public static void main(String[] args) {
        Scanner userInput = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Enter height");

        int height = userInput.nextInt();  // Read user input
        if(height <= 0){
            System.out.println("Error input!!!");
        }
        for (int i = 0; i < height; i++){
            for (int x = 0; x < i+1; x++){
                if((x+i)%2 == 0){
                    if(x == i){
                        System.out.println("AA");
                    }
                    else{
                        System.out.print("AA");
                    }
                }
                else {
                    if(x == i){
                        System.out.println("BB");
                    }
                    else{
                        System.out.print("BB");
                    }
                }
            }
        }
    }
}
