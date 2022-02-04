import java.util.*;

class InvalidInputException extends Exception{
    InvalidInputException(String exceptionText){
        super(exceptionText);
    }
}

class ExceptionHandling{
    
    static int validate(int no)throws InvalidInputException{
        if(no<100)
            throw new InvalidInputException("Invalid Input");
        System.out.println("Valid input");
        return no;
    }
    
    public static void main(){
        Scanner sc=new Scanner(System.in);

        try{
            if(1/0==0);
        }
        catch(ArithmeticException m){
            System.out.println(m);
        }
        
        try{
            try{
                int a[]=new int[1];
                a[-1]=5;
            }
            catch(ArrayIndexOutOfBoundsException e){
                System.out.println(e);
            }
            
        }
        catch(Exception e){
            System.out.println("Exception handled");
        }
        
        try{
            System.out.println("1 for NullPointer exception 2 for InputMismatch");
            int n=sc.nextInt();
            int arr[]=new int[5];
            String s=null;
            if(n==1)
                s.length();
            if(n==2){
                s="hi";
                n=Integer.parseInt(s);
            }
        }
        catch(NullPointerException e){
            System.out.println(e);
        }
        catch(NumberFormatException e){
            System.out.println(e);
        }
        
        catch(Exception e){
            System.out.println("handled");
        }
        
        try{
            System.out.println("enter less than 100 for error");
            int l=sc.nextInt();
            l=validate(l);
        }
        catch(InvalidInputException e){
            System.out.println(e);
        }
        
        finally{
            System.out.println("end of code");
        }
    }
}

class Thread1 implements Runnable{
	public void run(){
		try{
			int i=1;
			while(i<20){
				System.out.println(" "+ (i+=2)+ "-"+ Thread.currentThread().getPriority());
				Thread.currentThread().sleep(200);
			}
		}catch(Exception e){System.out.println(e);}
	}
}
	
class Thread2 extends Thread{
	public void run(){
		int i=0;
		while(i<20){
			System.out.println(" "+ (i+=2) +"-"+this.getName());
			try{this.sleep(250);}
			catch(Exception e){;}
		}
	}
}

class MultiThreading{
	public static void main(){
		Thread t1=new Thread(new Thread1());
		Thread2 t2=new Thread2();
		Thread t3=new Thread(new Thread1());		

		t1.setPriority(Thread.MAX_PRIORITY);
		t2.setName("thr2");
		
		t1.start();
		t2.start();
		t3.start();
		try{t3.join();}
		catch(Exception e){;}
	}
}

public class Expt11{
	public static void main(String []args){
		MultiThreading.main();
		ExceptionHandling.main();
	}
}

/*
C:\Users\Dell\Desktop\Jordan\Engineering\Second year\OOPM\Expts>java Expt11
 3-10
 3-5
 2-thr2
 5-10
 5-5
 4-thr2
 7-10
 7-5
 6-thr2
 9-10
 9-5
 8-thr2
 11-10
 11-5
 13-10
 13-5
 10-thr2
 15-10
 15-5
 12-thr2
 17-10
 17-5
 14-thr2
 19-10
 19-5
 16-thr2
 21-10
 21-5
 18-thr2
 20-thr2
java.lang.ArithmeticException: / by zero
java.lang.ArrayIndexOutOfBoundsException: Index -1 out of bounds for length 1
1 for NullPointer exception 2 for InputMismatch
1
java.lang.NullPointerException: Cannot invoke "String.length()" because "<local3
>" is null
enter less than 100 for error
12
InvalidInputException: Invalid Input
end of code
*/