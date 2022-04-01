package Lab3;

public class Plane {
    private PlaneSeat[] seat = new PlaneSeat[12];
    private int numEmptySeat;

    public Plane() {
        this.numEmptySeat = 12;
        for (int i = 0; i < 12; i ++){
            seat[i] = new PlaneSeat(i+1);
        }
    }

    private PlaneSeat[] sortSeats() {
        PlaneSeat[] tempArr = seat.clone();
        PlaneSeat temp ;
        for (int i = 0; i < 12; i ++){
            for (int x = 10; x >= i; x--){
                if(tempArr[x+1].getCustomerID() < tempArr[x].getCustomerID()){
                    temp = tempArr[x+1];
                    tempArr[x+1] = tempArr[x];
                    tempArr[x] = temp;
                }
            }
        }

        return tempArr;
    }

    public void showNumEmptySeats(){
        System.out.println("There are "+ numEmptySeat +" empty seats." );
    }

    public void showEmptySeats(){
        for (int i = 0; i < 12; i ++){
            if (!seat[i].isOccupied()){
                System.out.println("SeatID "+(i+1));
            }
        }
    }

    public void showAssignedSeats(boolean bySeatId){
        if (bySeatId){
            for (int i = 0; i < 12; i ++){
                if (seat[i].isOccupied()){
                    System.out.println("SeatID "+(i+1)+" assigned to CustomerID "+seat[i].getCustomerID());
                }
            }
        }
        else{
            PlaneSeat[] temp = sortSeats();
            for (int i = 0; i < 12; i ++){
                if (temp[i].isOccupied()){
                    System.out.println("SeatID "+temp[i].getSeatID()+" assigned to CustomerID "+temp[i].getCustomerID());
                }
            }
        }

    }

    public void assignSeat(int seatId, int cust_id){
        seat[seatId-1].assign(cust_id);
        numEmptySeat = numEmptySeat - 1;


    }

    public void unAssignSeat(int seatId){
        seat[seatId-1].unAssign();
        numEmptySeat = numEmptySeat + 1;
    }

}
