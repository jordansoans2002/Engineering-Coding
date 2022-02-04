public class rectangle extends Shape{
	
	rectangle(int l,int b){
		super(l,b);
	}

	void display(){
		System.out.println("Length is "+super.length+" Base is "+super.breadth);
	}

	void calculate_area(){
		System.out.println("Area is "+super.length*super.breadth);
	}
}