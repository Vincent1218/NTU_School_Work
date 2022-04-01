package Lab4a;

public class SalePerson implements Comparable<SalePerson>{
    private String firstName;
    private String lastName;
    private int totalSales;

    public SalePerson(String firstName,  String lastName, int totalSales){
        this.firstName = firstName;
        this.lastName = lastName;
        this.totalSales = totalSales;
    }
    public String toString(){
        return (this.lastName + "," + this.firstName + ":" + this.totalSales);
    }

    public boolean equals(SalePerson sp){
        if ((this.firstName == sp.firstName) && (this.lastName == sp.lastName)){
            return true;
        }
        else{
            return false;
        }
    }

    public int compareTo(SalePerson sp){
        if(this.totalSales > sp.totalSales){
            return 1;
        }
        else if (this.totalSales < sp.totalSales){
            return -1;
        }
        else{
            if (((this.lastName).compareTo(sp.lastName))<0){
                return 1;
            }
            else{
                return -1;
            }
        }
    }

    public String getFirstName(){
        return this.firstName;
    }

    public String getLastName(){
        return this.lastName;
    }

    public int getTotalSales(){
        return this.totalSales;
    }
}
