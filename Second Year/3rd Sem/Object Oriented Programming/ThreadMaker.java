class ThreadMaker1 extends Thread implements Runnable{
	public void run(){
		int i=5;
		while(i!=0){
			try{
			System.out.println(i--);
			this.sleep(100);
			}
			catch(Exception e){System.out.println("hey");}
		}
	}
}

class ThreadMaker2 extends Thread implements Runnable{
	public void run(){
		int i=20;
		while(i!=5){
			try{
			System.out.println(i--);
			this.sleep(100);
			}
			catch(Exception e){;}
		}
	}
}


public class ThreadMaker{
	public static void main(String []args){
		Thread t1=new Thread(new ThreadMaker1());
		ThreadMaker1 t2=new ThreadMaker1();
		ThreadMaker2 t3=new ThreadMaker2();

		t1.start();

		try{t1.join();}
		catch(Exception e){;}

		t2.start();

		try{t2.join(6000);}
		catch(Exception e){;}
		
		t3.start();
	}
}
