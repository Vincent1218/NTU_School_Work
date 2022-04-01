package Lab3;

import java.util.Scanner;

public class PlaneApp {
    public static void main(String[] args){
        Plane plane = new Plane();
        int choice;

        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("Perform the following actions:");
            System.out.println("1: Show number of empty seats");
            System.out.println("2: Show the list of empty seats");
            System.out.println("3: Show the list of seat assignments by seat ID");
            System.out.println("4: Show the list of seat assignments by customer ID");
            System.out.println("5: Assign a customer to a seat");
            System.out.println("6: Remove a seat assignment");
            System.out.println("7: Exit");

            System.out.println("Enter Number of Choice:");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    plane.showNumEmptySeats();
                    break;
                case 2:
                    System.out.println("The following seats are empty:");
                    plane.showEmptySeats();
                    break;
                case 3:
                    System.out.println("The seat assignments are as follow:");
                    plane.showAssignedSeats(true);
                    break;
                case 4:
                    System.out.println("The seat assignments are as follow:");
                    plane.showAssignedSeats(false);
                    break;
                case 5:
                    System.out.println("Assigning Seat ..");
                    System.out.println(" Please enter SeatID: ");
                    int p1 = sc.nextInt();
                    if(( p1 > 12) || (p1 < 1)){
                        System.out.println("SeatId out of range!");
                        break;
                    }
                    System.out.println(" Please enter CustomerID: ");
                    int p2 = sc.nextInt();
                    plane.assignSeat(p1,p2);
                    break;
                case 6: /* add extractOddDigits() call */
                    System.out.println("Enter SeatID to unassign customer from: ");
                    int e1 = sc.nextInt();
                    plane.unAssignSeat(e1);
                    break;
                case 7: System.out.println("Exiting...");
            }
        } while (choice < 7);
    }


}
