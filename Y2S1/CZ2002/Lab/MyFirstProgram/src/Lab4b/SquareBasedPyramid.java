package Lab4b;

public class SquareBasedPyramid implements Shape{
    private double height;
    private double base;
    private String shape;

    public SquareBasedPyramid(double height, double base){
        this.height = height;
        this.base = base;
        this.shape = "Square-Based Pyramid";
    }
    public String getShape(){
        return this.shape;
    }
    public double getArea(){
        double l = Math.sqrt((this.height*this.height) + (((this.base)/2)*((this.base)/2)));
        Triangle tri = new Triangle(l,base);
        Square sq = new Square(base);

        return (4 * tri.getArea() + sq.getArea() );
    }
}
