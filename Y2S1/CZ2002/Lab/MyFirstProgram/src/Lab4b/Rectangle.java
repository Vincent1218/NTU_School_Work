package Lab4b;

public class Rectangle implements Shape{
    private double length;
    private double breath;
    private String shape;

    public Rectangle(double length, double breath){
        this.length = length;
        this.breath = breath;
        this.shape = "Rectangle";
    }
    public String getShape(){
        return this.shape;
    }
    public double getArea(){
        return (this.length * this.breath);
    }
}
