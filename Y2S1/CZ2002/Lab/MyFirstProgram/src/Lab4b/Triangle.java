package Lab4b;

public class Triangle implements Shape{
    private double height;
    private double base;
    private String shape;

    public Triangle(double height, double base){
        this.height = height;
        this.base = base;
        this.shape = "Triangle";
    }
    public String getShape(){
        return this.shape;
    }
    public double getArea(){
        return (this.height * this.base * 0.5);
    }
}
