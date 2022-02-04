package myPack;
/*to complie package file: javac -d <directory of file> <file name>
if same directory: javac -d . <file name> ('.' means current directory)*/

/*to execute java <package name>.<file name>*/
public class Simple{
	public static void main(String []args){
		System.out.println("Welcome to Package");
	}
	void msg(){
		System.out.println("you are in package myPack");
	}
}