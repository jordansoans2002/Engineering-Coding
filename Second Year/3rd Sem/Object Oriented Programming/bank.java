import java.util.Scanner;
public class bank{
	String branch;int min_bal;
	
	void deposit(int sum)
	{
		Account.deposit(sum);
	}

	void withdraw(int sum){
		if(Account.withdraw(sum))
			System.out.println(sum+" is debited");
		else
			System.out.println("insufficient balance");
		}
		if(Account.bal<min_bal)
			System.out.println("you have less than minimum balance.\nPlease deposit "+(min_bal-Account.bal)+" in 24 hours");
	}

	void changeDetails(){
		Scanner sc=new Scanner(System.in);
		System.out.println("enter new phone_no");
		Account.roll_no=sc.nextInt();
	}
}