package Lab4b;

public class Circle implements Shape{
    private double radius;
    private String shape;

    public Circle(double radius){
        this.radius = radius;
        this.shape = "Circle";
    }

    public String getShape(){
        return this.shape;
    }
    public double getArea(){
        return (this.radius * this.radius * Math.PI);
    }

    public double getPerimeter(){
        return (this.radius * 2 * Math.PI);
    }
}
