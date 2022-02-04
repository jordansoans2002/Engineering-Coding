public class car extends vehicle{
    String name;int price,regNo;
    
    car(String name,String colour,int price,int speed){
        super("petrol",colour,4,speed);
        this.name=name;
        this.price=price;
    }
    
    void getName(){ System.out.println("Name of car is "+name); }
     
    void getPrice(){ System.out.println("Price of car is "+price); }
    
    /*static*/ void run(){//only 1 static method can override another static function
        super.run();//wont work for static functs and variables
        //vehicle.run();//bcz we made run static in Vehicle
        System.out.println("Car is running");
    }
     
    void disp(){
        super.disp();
        getName();
        getPrice();
    }
}
