import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    int k, noOfPoints;
    ArrayList<Point> points = new ArrayList<>();
    ArrayList<ArrayList<Point>> clusters;

    public static void main(String[] args) {
        Main main = new Main();
        main.input();
        main.kmeans();
    }

    void input(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of clusters ");
        k = sc.nextInt();
        clusters = new ArrayList<>(k);
        System.out.print("Enter the number of points ");
        noOfPoints = sc.nextInt();

        for(int i=0;i<noOfPoints;i++){
            System.out.print("Enter x coordinate ");
            double x = sc.nextDouble();
            System.out.print("Enter y coordinate ");
            double y = sc.nextDouble();
            points.add(new Point(x,y));
        }
    }

    void kmeans(){
        HashSet<Point> c = new HashSet<>();
        while(c.size()<k){
            c.add(points.get((int)(Math.random()*noOfPoints)));
        }

        ArrayList<Point> centroids = new ArrayList<>(c);
        for(int i=0;i<k;i++){
            for(Point p:points)
                p.updateCluster(centroids.get(i),i);
        }

        boolean flag = false;
        do{
            for(int i=0;i<k;i++){
                double x=0,y=0,k=0;
                for(Point p:points){
                    if(p.cluster==i){
                        k++;
                        x+=p.x;
                        y+=p.y;
                    }
                }
                centroids.set(i,new Point(x/k,y/k));
            }

            for(int i=0;i< k;i++){
                for(Point p:points){
                    if(p.updateCluster(centroids.get(i),i))
                        flag=true;
                }
            }
        }while (flag);

        for(int i=0;i<k;i++){
            System.out.println("Cluster "+(i+1)+" centroid: "+centroids.get(i).x+","+centroids.get(i).y);
            for(Point p : points){
                if(p.cluster == i){
                    System.out.println(p.x+","+p.y);
                }
            }
            System.out.println();
        }

    }

    class Point{
        double x,y,dist = -1;
        int cluster;
        Point(double x, double y){
            this.x = x;
            this.y = y;
        }

        boolean updateCluster(Point centroid, int cluster){
            double dist = Math.sqrt(Math.pow((x- centroid.x),2)+Math.pow((y- centroid.y),2));
            if(this.dist==-1 || this.dist>dist){
                this.dist = dist;
                if(this.cluster != cluster){
                    this.cluster = cluster;
                    return true;
                }
            }
            return false;
        }
    }
}
