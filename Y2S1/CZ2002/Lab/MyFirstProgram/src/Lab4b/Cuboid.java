package Lab4b;

public class Cuboid implements Shape{
    private double length;
    private double breath;
    private double height;
    private String shape;

    public Cuboid(double length, double breath, double height){
        this.length = length;
        this.breath = breath;
        this.height = height;
        this.shape = "Cuboid";

    }
    public String getShape(){
        return this.shape;
    }
    public double getArea(){
        Rectangle rec1 = new Rectangle(length,breath);
        Rectangle rec2 = new Rectangle(length,height);
        Rectangle rec3 = new Rectangle(breath,height);

        return (2 * rec1.getArea() + 2 * rec2.getArea() + 2 * rec3.getArea());
    }
}