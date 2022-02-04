import java.io.*;
public class Writing_FileOutputStream{
	public static void main(String []args){
		BufferedReader in=new BufferedReader(System.in);
		FileOutputStream out=new FileOutputStream("text.txt");
		System.out.println("enter characters");
		char ip=in.readLine().charAt(0);
		while(ip!=''){
			out.write(ip);
			ip=in.readLine().charAt(0);
		}
	}
}