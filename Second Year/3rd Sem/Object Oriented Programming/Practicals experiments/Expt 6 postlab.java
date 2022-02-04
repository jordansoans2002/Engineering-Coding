import java.util.*;
public class Main{
        public static void main(String []args){
            Scanner sc=new Scanner(System.in);
            System.out.println("enter no of rows and columns for 1st array");
            int r=sc.nextInt();
            int c=sc.nextInt();
            int a[][]=new int[r][c];
            int b[][]=new int[r][c];
            System.out.println("enter the elements of 1st array");
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++)
                    a[i][j]=sc.nextInt();
            }
            System.out.println("enter the elements of 2nd array");
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++)
                    b[i][j]=sc.nextInt();
            }
            System.out.println("Sum of arrays is:");
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++)
                    System.out.print((a[i][j]+b[i][j])+" ");
                System.out.println();
            }
            System.out.println("Difference of arrays is:");
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++)
                    System.out.print((a[i][j]-b[i][j])+" ");
                System.out.println();
            }
        }
    }

/*
enter no of rows and columns for 1st array
2
5
enter the elements of 1st array
1
2
3
4
5
6
7
8
9
10
enter the elements of 2nd array
10
9
8
7
6
5
4
3
2
1
Sum of arrays is:
11      11      11      11      11
11      11      11      11      11
Difference of arrays is:
-9      -7      -5      -3      -1
1       3       5       7       9
*/