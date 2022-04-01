package com.company;

import java.util.Scanner;

public class P2 {
    public static void main(String[] args) {
        Scanner userInput = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Enter Salary");
        int salary = userInput.nextInt();  // Read user salary

        System.out.println("Enter Merit");
        int merit = userInput.nextInt();  // Read user merit

        if ((salary >= 800) && (salary <= 899)){
            System.out.println("Salary: "+salary+","+"Merit: "+merit+","+"Grade: A");
        }
        else if ((salary >= 700) && (salary <= 799)){
            if(merit < 20){
                System.out.println("Salary: "+salary+","+"Merit: "+merit+","+"Grade: B");
            }
            else{
                System.out.println("Salary: "+salary+","+"Merit: "+merit+","+"Grade: A");
            }
        }
        else if ((salary >= 650) && (salary <= 699)){
            System.out.println("Salary: "+salary+","+"Merit: "+merit+","+"Grade: B");
        }
        else if ((salary >= 600) && (salary <= 649)){
            if(merit < 10){
                System.out.println("Salary: "+salary+","+"Merit: "+merit+","+"Grade: C");
            }
            else{
                System.out.println("Salary: "+salary+","+"Merit: "+merit+","+"Grade: B");
            }
        }
        else if ((salary >= 500) && (salary <= 599)){
            System.out.println("Salary: "+salary+","+"Merit: "+merit+","+"Grade: C");
        }
        else{
            System.out.println("Salary out of range");
        }
    }
}
