import java.util.*;
public class Main{
    public static void Main(){
        Scanner sc=new Scanner(System.in);
        car newCar[]=new car[10];
        bike newBike[]=new bike[10];
        vehicle newVehicle[]=new vehicle[10];
        int c=0,b=0,v=0,choice=0;
        do{
            System.out.println("Enter the type of vehicle to register");
            String vehicleType=sc.next();
            switch(vehicleType){
                case "car":
                {
                    System.out.println("enter the name, colour, price and top speed");
                    sc.next();
                    String name=sc.nextLine();
                    sc.next();
                    String colour=sc.nextLine();
                    int price=sc.nextInt();
                    int topSpeed=sc.nextInt();
                    newCar[c++]=new car(name,colour,price,topSpeed);
                    break;
                }
                
                case "bike":
                {
                    System.out.println("Enter the brand, colour, price and top speed");
                    sc.next();
                    String brand=sc.nextLine();
                    sc.next();
                    String colour=sc.nextLine();
                    int price=sc.nextInt();
                    int topSpeed=sc.nextInt();
                    newBike[b++]=new bike(brand,colour,price,topSpeed);
                    break;
                }
                
                default:
                    System.out.println("this vehicle doesnt exist in out server creating a new vehicle");
                
                case "vehicle":
                {
                    System.out.println("enter the power source, colour, no of wheels and the top speed of the vehicle");
                    sc.next();
                    String powerSource=sc.nextLine();
                    sc.next();
                    String colour=sc.nextLine();
                    int noOfWheels=sc.nextInt();
                    int topSpeed=sc.nextInt();
                    newVehicle[v++]=new vehicle(powerSource,colour,noOfWheels,topSpeed);
                }
            }
            System.out.println("press any key to continue, 0 to exit");
            choice=sc.nextInt();
        }while(choice!=0);
        //vehicle v=new vehicle("electric","white",4,120);
        //bike hero=new bike("hero","red",100000,80);
        //car honda=new car("honda","silver",1000000,120);
        if(v>0){
            for(int i=0;i<v;i++)
                newVehicle[0].disp();
        }
        System.out.println();
        if(b>0){
            for(int i=0;i<b;i++){
                newBike[0].disp();
                newBike[0].run();
            }
        }
        System.out.println();
        if(c>0){
            for(int i=0;i<c;i++){
                newCar[0].disp();
                newCar[0].run();
            }
        }
    }
}
