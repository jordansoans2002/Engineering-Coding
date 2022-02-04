import java.util.*;
public class MockTest_OOPM_9165{
    String name,type;int accNo,bal;
    static int acc_no=0;
    
    MockTest_OOPM_9165()
    {
        accNo=acc_no;
    }
    
    void openAcc(String name,String type){
        System.out.println("You have opened new account");
        System.out.println("Your account no is "+accNo);
        this.name=name;
        this.type=type;
    }
    
    void showInfo(){
        System.out.println("Name: "+this.name);
        System.out.println("Account number: "+this.accNo);
        System.out.println("Account type: "+this.type);
        System.out.println("Balance: "+this.bal);
    }
    
    void deposit(int dep){
        System.out.println("You are depositing "+dep+" rupees");
        bal=bal+dep;
    }
    
    void withdraw(int with){
        if(with<bal){
            bal=bal-with;
            System.out.println("You have withdrawn "+with+" rupees");
        }
        else
            System.out.println("Insufficient balance");
        System.out.println("Remaining balance is "+bal);
    }

    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        MockTest_OOPM_9165 acc[]=new MockTest_OOPM_9165[10];
        int i=0,c=0,acNo=0;boolean flag=false;
        do{
            System.out.println("Select your option 1.open 2.deposit 3.withdraw 4.show info  0 to exit");
            c=sc.nextInt();
            if(acc_no==0&&c!=1){
                System.out.println("no account");
                c=5;
            }
            switch(c)
            {
                case 0:
                    break;
                    
                case 1:
                {
                    acc[++acc_no]=new MockTest_OOPM_9165();
                    System.out.println("Enter your name and account type you want");
                    String nm=sc.nextLine();
                    nm=sc.nextLine();
                    String typ=sc.nextLine();
                    acc[acc_no].openAcc(nm,typ);
                    break;
                }
                case 2:
                {
                    System.out.println("Enter account no and amount to deposit");
                    acNo=sc.nextInt();
                    for(int j=1;j<=acc_no;j++){
                        if(j==acNo)
                            flag=true;
                    }
                    if(!flag){
                        System.out.println("invalid account no");
                        break;
                    }
                    int sum=sc.nextInt();
                    acc[acNo].deposit(sum);
                    break;
                }
                case 3:
                {
                    System.out.println("Enter account no and amount to be withdrawn");
                    acNo=sc.nextInt();
                    for(int j=1;j<=acc_no;j++){
                        if(j==acNo)
                            flag=true;
                    }
                    if(!flag){
                        System.out.println("invalid account no");
                        break;
                    }
                    int sum=sc.nextInt(); 
                    acc[acNo].withdraw(sum);
                    break;
                }
                
                case 4:
                {
                    System.out.println("Enter account no");
                    acNo=sc.nextInt();
                    for(int j=1;j<=acc_no;j++){
                        if(j==acNo)
                            flag=true;
                    }
                    if(!flag){
                        System.out.println("invalid account no");
                        break;
                    }
                    acc[acNo].showInfo();
                    break;
                }
                
                default:
                    System.out.println("invalid input");
            }
        }while(c!=0);
    }
}
