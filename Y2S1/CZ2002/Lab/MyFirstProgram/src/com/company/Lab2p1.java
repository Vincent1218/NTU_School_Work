package com.company;

import java.util.Scanner;
import java.lang.Math;

public class Lab2p1 {
    public static void main(String[] args)
    {
        int choice;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("Perform the following methods:");
            System.out.println("1: miltiplication test");
            System.out.println("2: quotient using division by subtraction");
            System.out.println("3: remainder using division by subtraction");
            System.out.println("4: count the number of digits");
            System.out.println("5: position of a digit");
            System.out.println("6: extract all odd digits");
            System.out.println("7: quit");
            choice = sc.nextInt();
            switch (choice) {
                case 1: /* add mulTest() call */
                    mulTest();
                    break;
                case 2: /* add divide() call */
                    System.out.println("Enter first number: ");
                    int d1 = sc.nextInt();
                    System.out.println("Enter second number: ");
                    int d2 = sc.nextInt();
                    System.out.println(d1+"/"+d2+"="+divide(d1,d2));
                    break;
                case 3: /* add modulus() call */
                    System.out.println("Enter first number: ");
                    int m1 = sc.nextInt();
                    System.out.println("Enter second number: ");
                    int m2 = sc.nextInt();
                    System.out.println(m1+"%"+m2+"="+modulus(m1,m2));
                    break;
                case 4: /* add countDigits() call */
                    System.out.println("Enter number: ");
                    int c1 = sc.nextInt();
                    if(c1<0){
                        System.out.println("n: "+c1+" - Error input!!!");
                    }
                    else{
                        System.out.println("n: "+c1+" - count = "+countDigits(c1));
                    }
                    break;
                case 5: /* add position() call */
                    System.out.println("Enter number: ");
                    int p1 = sc.nextInt();
                    System.out.println("Enter digit: ");
                    int p2 = sc.nextInt();
                    System.out.println("Position: "+position(p1,p2));
                    break;
                case 6: /* add extractOddDigits() call */
                    System.out.println("Enter number: ");
                    int e1 = sc.nextInt();
                    if(extractOddDigits(e1)==-2){
                        System.out.println("offDigits: "+"Error input!!!");
                    }
                    else{
                        System.out.println("offDigits: "+extractOddDigits(e1));
                    }
                    break;
                case 7: System.out.println("Program terminating...");
            }
        } while (choice < 7);
    }

    public static void mulTest(){
        Scanner sc = new Scanner(System.in);
        int x = 5;
        int count = 0;
        while (x>0){
            int a = (int)(Math.random()*9)+1;
            int b = (int)(Math.random()*9)+1;
            System.out.println("How much is "+a+" times "+b+"?");
            int ans = sc.nextInt();
            if (ans == a*b){
               count ++;
            }
            x--;
        }
        System.out.println(count+" answers out of 5 are correct.");
    }
    public static int divide(int m,int n){
        int count = 0;
        while(m>=n){
            m-=n;
            count ++;
        }
        return count;
    }
    public static int modulus(int m,int n){
        while(m>=n){
            m-=n;
        }
        return m;
    }
    public static int countDigits(int m){
        int count = 1;
        if(m<0){
            return -1;
        }
        while((int)(m/10)>0){
            count ++;
            m/=10;
        }
        return count;
    }
    public static int position(int m, int n){
        int count = 1;
        while((int)(m)>0){
            if(m%10 == n){
                return count;
            }
            count ++;
            m/=10;
        }
        return -1;
    }
    public static long extractOddDigits(long m){
        if(m<0){
            return -2;
        }
        int c = 0;
        int ans = 0;
        while((int)(m)>0){
            if(m%2 == 1){
                ans += (m%10)*(Math.pow(10,c));
                c ++;
            }
            m/=10;
        }
        return (ans>0) ? ans : -1 ;
    }
}