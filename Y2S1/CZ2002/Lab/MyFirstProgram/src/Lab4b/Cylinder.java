package Lab4b;

public class Cylinder implements Shape{
    private double height;
    private double radius;
    private String shape;

    public Cylinder(double height, double radius){
        this.height = height;
        this.radius = radius;
        this.shape = "Cylinder";
    }
    public String getShape(){
        return this.shape;
    }
    public double getArea(){
        Circle cr1 = new Circle(radius);
        double width = cr1.getPerimeter();
        Rectangle rec = new Rectangle(height,width);
        double upArea = rec.getArea();
        double bottomArea = cr1.getArea();
        return (upArea + bottomArea);
    }
}
