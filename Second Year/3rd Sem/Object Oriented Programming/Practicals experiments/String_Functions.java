import java.util.Scanner;
public class String_Fuctions{
	public static void main(String []args){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter a string");
		String s=sc.nextLine();
		int l=s.length();
		System.out.println("length is "+l);
		s=s.concat("java");
		System.out.println("adding java to the end: "+s);
		int c=s.compareTo("hello");
		System.out.println(s+" compared to hello is: "+c);
		s=s.replace("hello","hi");
		System.out.println(s);
		String s1=s.toLowerCase();
		System.out.println("in lowercase: "+s1);
	}
}

/*
Enter a string
Hello
length is 5
adding java to the end: Hello Java
Hello Java compared to hello is: 5
Hello Java
in lowercase: hello java
*/