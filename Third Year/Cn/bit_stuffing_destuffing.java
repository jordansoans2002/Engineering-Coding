import java.util.Scanner;
public class Main
{
  static String pattern=" 0111 1110 ";
	public static void main(String[] args) {
		System.out.println("Enter the input bit string");
	  de_stuff(stuff(new Scanner(System.in).nextLine()));
	}
	static String stuff(String ip){
	  int k=0;String op="";
	  for(int i=0;i<ip.length();i++){
	    char c=ip.charAt(i);
	    if(c=='1') k++;
	    else k=0;
	    op=op+c;
	    if(k%5==0) op=op+"0";
	    
	  }
	  System.out.println("Bit String After stuffing: "+pattern+op+pattern);
	  return op;
	}
	static void de_stuff(String ip){
	  int k=0;String op="";
  	for(int i=0;i<ip.length();i++){
	    char c=ip.charAt(i);
	    if(c=='1') k++;
	    else k=0;
	    op=op+c;
	    if(k%5==0) i++;
	  }
  	System.out.println("Bit String After de-stuffing: "+pattern+op+pattern);
	}
}
