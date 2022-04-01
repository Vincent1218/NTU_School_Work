package Lab4b;

public class Square implements Shape{
    private double length;
    private String shape;

    public Square(double length){
        this.length = length;
        this.shape = "Square";
    }
    public String getShape(){
        return this.shape;
    }
    public double getArea(){
        return (this.length * this.length);
    }
}
