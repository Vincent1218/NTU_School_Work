package Lab4b;

public class Cube implements Shape{
    private double length;
    private String shape;

    public Cube(double length){
        this.length = length;
        this.shape = "Cube";
    }
    public String getShape(){
        return this.shape;
    }
    public double getArea(){
        Square sq = new Square(length);
        return (6*sq.getArea());
    }
}
