public interface SimpleCalculator{
    void add(int a,int b);
    void sub();
}

public interface SciCalculator{
    int factorial();
    void square();
}

import java.util.*;
public class Calculator implements SimpleCalculator, SciCalculator{
    int a,b;
    
    public void add(int a,int b){
        System.out.print(a+b);
    }
    public void sub(){
        System.out.print(a-b);
    }
    public int factorial(){
        int p=1;
        while(a!=0)
            p=p*a--;
        return p;
    }
    public void square(){
        System.out.print(a*a);
    }
    
    public void main(String []args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Choose your option 1.add 2.subtract 3.factorial 4.square");
        int n=sc.nextInt(),t=0;
        switch(n)
        {
            case 1:
            case 2:
                System.out.println("Enter the nos to be added");
                a=sc.nextInt();
                b=sc.nextInt();
                if(n==1){
                    System.out.println("sum is ");
                    add(a,b);
                }
                else{
                    System.out.println("difference is ");
                    sub();
                }
                break;
            case 3:
                System.out.println("Factorial is "+factorial());
                break;
            case 4:
                System.out.println("Square is ");
                square();
                break;
            default:
                System.out.println("Invalid input");
        }
    }
}

/*
Choose your option 1.add 2.subtract 3.factorial 4.square
1
Enter the nos to be added
10 20
sum is 
30

Choose your option 1.add 2.subtract 3.factorial 4.square
3
Enter the number
5
Factorial is 120
*/
