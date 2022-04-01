package Lab4b;
import java.lang.Math;

public class Cone implements Shape{
    private double height;
    private double radius;
    private String shape;

    public Cone(double height, double radius){
        this.height = height;
        this.radius = radius;
        this.shape = "Cone";

    }
    public String getShape(){
        return this.shape;
    }
    public double getArea(){
        Circle cr1 = new Circle(radius);
        double l = Math.sqrt((height * height) + (radius * radius));
        double upArea = (cr1.getPerimeter()/ (2)) * (l);
        double bottomArea = cr1.getArea();
        return (upArea + bottomArea);
    }
}
