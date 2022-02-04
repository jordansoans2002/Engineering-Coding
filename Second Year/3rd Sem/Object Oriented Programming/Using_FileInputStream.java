import java.io.*;
public class Using_FileInputStream{
	public static void main(String []args){
		try{
			FileInputStream in=new FileInputStream("C:\\Users\\Dell\\Desktop\\Jordan\\Java\\text.txt");
			int ip=in.read();
			while(ip!=-1){
				System.out.print((char)ip);
				ip=in.read();
			}
		}catch(Exception e){System.out.println(e);}
	}
}