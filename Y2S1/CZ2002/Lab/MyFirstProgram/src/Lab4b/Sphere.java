package Lab4b;

public class Sphere implements Shape{
    private double radius;
    private String shape;

    public Sphere(double radius){
        this.radius = radius;
        this.shape = "Sphere";
    }
    public String getShape(){
        return this.shape;
    }
    public double getArea(){
        return (4 * Math.PI * radius * radius);
    }
}
