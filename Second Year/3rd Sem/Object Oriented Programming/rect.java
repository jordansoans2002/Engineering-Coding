import java.util.*;
public class rect{
	int l,b;
		
	rect(){
		l=0;b=0;
	}

	rect(int l1,int b1){
		l=l1;
		b=b1;
	}
	void input(){
		Scanner sc=new Scanner(System.in);
		System.out.println("enter len and breadth");
		l=sc.nextInt();
		b=sc.nextInt();
	}

	void getData(){
		System.out.println("length is "+l+"width is "+b);
	}
	
	int getArea(){
		return l*b;
	}
}