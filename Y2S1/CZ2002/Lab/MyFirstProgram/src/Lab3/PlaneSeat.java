package Lab3;

public class PlaneSeat{

    private int seatId;
    private boolean assigned;
    private int customerId;

    public PlaneSeat(int seat_id) {
        this.seatId = seat_id;
        this.assigned = false;
        this.customerId = 0;
    }

    public int getSeatID() {
        return seatId;
    }

    public int getCustomerID() {
        return customerId;
    }

    public boolean isOccupied() {
        return assigned;
    }

    public void assign(int cust_id){
        if(this.assigned){
            System.out.println("Seat already assigned to a customer.");
            return;
        }
        this.customerId = cust_id;
        this.assigned = true;
        System.out.println("Seat assigned!");
    }

    public void unAssign(){
        if(!this.assigned){
            System.out.println("Seat has not assigned to a customer.");
            return;
        }
        assigned = false;
        System.out.println("Seat Unassigned!");
    }

}
