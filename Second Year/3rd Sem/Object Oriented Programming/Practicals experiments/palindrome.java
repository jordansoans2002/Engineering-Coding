import java.util.*;
public class palindrome{
	public static void main(String []args){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the string to be checked");
		String s=sc.nextLine();
		String s1="";char c;
		for(int i=0;i<s.length();i++){
			c=s.charAt(i);
			s1=c+s1;
		}
		if(s1.equalsIgnoreCase(s))
			System.out.println("Palindrome");
		else
			System.out.println("Not palindrome");
	}
}
/*
Enter the string to be checked
maddam
Palindrome

Enter the string to be checked
maddam
Palindrome
*/
