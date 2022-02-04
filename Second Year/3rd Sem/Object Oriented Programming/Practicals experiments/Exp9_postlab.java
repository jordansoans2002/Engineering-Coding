class Shape{
	int length,breadth;
	
	Shape(int length,int breadth){
		this.length=length;
		this.breadth=breadth;
	}

	void disp(){
		System.out.println("length is "+length+" breadth is "+breadth);
	}

	void calculate_area(){
		System.out.println("area is "+length*breadth);
	}
}

class Triangle extends Shape{

	Triangle(int l,int b){
		super(l,b);
	}

	void display(){
		System.out.println("Height is "+super.length+" Base is "+super.breadth);
	}
	
	void calculate_area(){
		System.out.println("Area of triangle is "+0.5*super.length*super.breadth);
	}
}

class Rectangle extends Shape{
	
	Rectangle(int l,int b){
		super(l,b);
	}

	void display(){
		System.out.println("Length is "+super.length+" Base is "+super.breadth);
	}

}

class Square extends Rectangle{
	
	Square(int s){
		super(s,s);
	}
}

public class Exp9_postlab{
	public static void main(String []args){
		Shape shape=new Shape(12,13);
		Triangle triangle=new Triangle(30,60);
		Rectangle rect=new Rectangle(30,90);
		Square sq=new Square(45);
		shape.disp();
		shape.calculate_area();
		System.out.println();
		triangle.disp();
		triangle.calculate_area();
		System.out.println();
		rect.disp();
		rect.calculate_area();
		System.out.println();
		sq.disp();
		sq.calculate_area();
	}
}