public class triangle extends Shape{

	triangle(int l,int b){
		super(l,b);
	}

	void display(){
		System.out.println("Height is "+super.length+" Base is "+super.breadth);
	}
	
	void calculate_area(){
		System.out.println("Area of triangle is "+0.5*super.length*super.breadth);
	}
}