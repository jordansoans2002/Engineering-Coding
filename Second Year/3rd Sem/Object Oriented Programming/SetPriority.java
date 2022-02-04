class Thread1 implements Runnable{
	public void run(){
		int i=20;
		while(i!=10)
			System.out.print(" "+ i-- + "-" + Thread.currentThread().getName());
		System.out.println();
	}
}

class Thread2 extends Thread{
	public void run(){	
		int i=10;
		while(i!=0){
			System.out.print(" " + i-- + "-" + Thread.currentThread().getPriority());
			if(this.isDaemon())
				System.out.print(" Daemon ");
			System.out.println();
		}
	}
}

public class SetPriority{
	public static void main(String []args){
		Thread t1=new Thread(new Thread1());
		Thread2 t2=new Thread2();
		Thread2 t3 = new Thread2();
		t1.setName("thr1");
		
		t1.setPriority(Thread.MAX_PRIORITY);
		t3.setPriority(Thread.MIN_PRIORITY);
		t2.setDaemon(true);

		t1.start();
		t2.start();
		t3.start();
	}
}
//C:\Users\Dell\Desktop\Jordan\Engineering\Second year\OOPM