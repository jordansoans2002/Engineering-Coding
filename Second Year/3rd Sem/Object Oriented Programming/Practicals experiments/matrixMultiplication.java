import java.util.*;
public class matrixMultiplication{
        public static void main(String []args){
            Scanner sc=new Scanner(System.in);
            System.out.println("enter no of rows and columns for 1st array");
            int r1=sc.nextInt();
            int c1=sc.nextInt();
            int a[][]=new int[r1][c1];
            System.out.println("enter the elements");
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++)
                    a[i][j]=sc.nextInt();
            }
            System.out.println("enter the no of columns for the 2nd array");
            int c2=sc.nextInt(),r2=c1;
            int b[][]=new int[r2][c2];
            System.out.println("enter the elements");
            for(int i=0;i<r2;i++){
                for(int j=0;j<c2;j++)
                    b[i][j]=sc.nextInt();
            }
            int c[][]=new int[r1][c2];
            int s=0;
            for(int i=0;i<r1;i++)
            {
                for(int j=0;j<c2;j++)
                {
                    for(int k=0;k<r2;k++)
                        c[i][j]+=a[i][k]*b[k][j];
                }
            }
            for(int i=0;i<r1;i++)
            {
                for(int j=0;j<c2;j++)
                    System.out.print(c[i][j]+"\t");
                System.out.println();
            }
        }
    }

/*
enter no of rows and columns for 1st array
2
3
enter the elements
1
2
3
4
5
6
enter the no of columns for the 2nd array
2
enter the elements
7
8
9
10
11
12
58      64
139     154
*/

Postlab
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



