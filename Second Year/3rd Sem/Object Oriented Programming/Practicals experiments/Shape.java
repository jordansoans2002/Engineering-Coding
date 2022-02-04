public class Shape{
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