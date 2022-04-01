package Lab4b;

import java.util.Scanner;

public class Shape2DApp {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        System.out.println ("How many shape do you want to count? ");
        int size = scan.nextInt();

        Shape[] shapeArr = new Shape[size];

        int x = 0;
        while(x < size){
            System.out.println ("Choose shape (input the index)");
            System.out.println ("1. Square");
            System.out.println ("2. Rectangle");
            System.out.println ("3. Triangle");
            System.out.println ("4. Circle");
            try {
                int choose = scan.nextInt();
                if (choose == 1) {
                    try {
                        System.out.println ("Enter length of one side of Square");
                        double l = scan.nextDouble();
                        shapeArr[x] = new Square(l);
                        x++;
                    } catch (Exception e) {
                        System.out.println("Please enter a valid number!");
                        scan.nextLine();
                    }
                } else if (choose == 2) {
                    try {
                        System.out.println ("Enter length of Rectangle");
                        double l = scan.nextDouble();
                        System.out.println ("Enter breath of Rectangle");
                        double b = scan.nextDouble();
                        shapeArr[x] = new Rectangle(l,b);
                        x++;
                    } catch (Exception e) {
                        System.out.println("Please enter a valid number!");
                        scan.nextLine();
                    }
                } else if (choose == 3) {
                    try {
                        System.out.println ("Enter height of Triangle");
                        double h = scan.nextDouble();
                        System.out.println ("Enter base of Triangle");
                        double b = scan.nextDouble();
                        shapeArr[x] = new Triangle(h,b);
                        x++;
                    } catch (Exception e) {
                        System.out.println("Please enter a valid number!");
                        scan.nextLine();
                    }
                } else if (choose == 4) {
                    try {
                        System.out.println ("Enter radius of Circle");
                        double r = scan.nextDouble();
                        shapeArr[x] = new Circle(r);
                        x++;
                    } catch (Exception e) {
                        System.out.println("Please enter a valid number!");
                        scan.nextLine();
                    }
                } else {
                    System.out.println("Please enter a valid number!");
                    scan.nextLine();
                }
            } catch(Exception e){
                System.out.println("Please enter a valid number!");
                scan.nextLine();
            }


        }

        int choose;
        do {
            System.out.println ("Choose action (input the index)");
            System.out.println ("1. Print Total Area of shape input");
            System.out.println ("2. Print Individual Area of shape input");
            System.out.println ("3. Exit");
            choose = scan.nextInt();
            if (choose == 1) {
                double total = 0;
                for (int i = 0; i < size; i++) {
                    total += (shapeArr[i].getArea());
                }
                System.out.println(total);
            } else if (choose == 2) {
                for (int i = 0; i < size; i++) {
                    System.out.print(shapeArr[i].getShape() + " ");
                    System.out.println(shapeArr[i].getArea());
                }
            } else {
                System.out.println("Exiting...");
            }
        }while (choose < 3);


    }
}
