import java.util.Scanner;
public class Main{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the size of the array");
		int n=sc.nextInt();
		int arr[]=new int[n];
		int max=0,min=9999;
		System.out.println("Enter the elements of the array less than 10000");
		for(int i=0;i<n;i++)
		    arr[i]=sc.nextInt();
		for(int i=0;i<arr.length;i++){
			if(arr[i]>max)
				max=arr[i];
			if(arr[i]<min)
				min=arr[i];
		}
		System.out.println("max: "+max+" min is "+min);
	}
}

/*
Enter the size of the array
5
Enter the elements of the array
5
-5
6
10
9
max: 10 min is -5
*/