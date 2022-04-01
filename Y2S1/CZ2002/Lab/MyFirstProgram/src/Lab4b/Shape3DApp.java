package Lab4b;

import java.util.Scanner;

public class Shape3DApp {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        System.out.println ("How many shape do you want to count? ");
        int size = scan.nextInt();

        Shape[] shapeArr = new Shape[size];

        int x = 0;
        while(x < size){
            System.out.println ("Choose shape (input the index)");
            System.out.println ("1. Sphere");
            System.out.println ("2. Cuboid");
            System.out.println ("3. Square-Based Pyramid");
            System.out.println ("4. Cube");
            System.out.println ("5. Cone");
            System.out.println ("6. Cylinder");
            try {
                int choose = scan.nextInt();
                if (choose == 1) {
                    try {
                        System.out.println("Enter radius of Sphere");
                        double r = scan.nextDouble();
                        shapeArr[x] = new Sphere(r);
                        x++;
                    } catch (Exception e) {
                        System.out.println("Please enter a valid number!");
                        scan.nextLine();
                    }
                } else if (choose == 2) {
                    try {
                        System.out.println("Enter length of Cuboid");
                        double l = scan.nextDouble();
                        System.out.println("Enter breath of Cuboid");
                        double b = scan.nextDouble();
                        System.out.println("Enter height of Cuboid");
                        double h = scan.nextDouble();

                        shapeArr[x] = new Cuboid(l, b, h);
                        x++;
                    } catch (Exception e) {
                        System.out.println("Please enter a valid number!");
                        scan.nextLine();
                    }
                } else if (choose == 3) {
                    try {
                        System.out.println("Enter height of Square-Based Pyramid");
                        double h = scan.nextDouble();
                        System.out.println("Enter base of Triangle");
                        double b = scan.nextDouble();
                        shapeArr[x] = new SquareBasedPyramid(h, b);
                        x++;
                    } catch (Exception e) {
                        System.out.println("Please enter a valid number!");
                        scan.nextLine();
                    }
                } else if (choose == 4) {
                    try {
                        System.out.println("Enter length of one side of Cube");
                        double l = scan.nextDouble();
                        shapeArr[x] = new Cube(l);
                        x++;
                    } catch (Exception e) {
                        System.out.println("Please enter a valid number!");
                        scan.nextLine();
                    }
                } else if (choose == 5) {
                    try {
                        System.out.println("Enter height of Cone");
                        double h = scan.nextDouble();
                        System.out.println("Enter radius of base circle");
                        double r = scan.nextDouble();
                        shapeArr[x] = new Cone(h, r);
                        x++;
                    } catch (Exception e) {
                        System.out.println("Please enter a valid number!");
                        scan.nextLine();
                    }
                } else if (choose == 6) {
                    try {
                        System.out.println("Enter height of Cylinder");
                        double h = scan.nextDouble();
                        System.out.println("Enter radius of base circle");
                        double r = scan.nextDouble();
                        shapeArr[x] = new Cylinder(h, r);
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
