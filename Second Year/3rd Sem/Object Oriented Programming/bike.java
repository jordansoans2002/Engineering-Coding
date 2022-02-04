public class bike extends vehicle{
    String brand;int price,regNo;
    bike(String brand,String colour, int price,int speed){
        super("petrol",colour,2,speed);
        this.brand=brand;
        this.price=price;
    }
    
    void getBrand(){ System.out.println("Brand is "+brand);}
    
    void getPrice(){ System.out.println("Price is "+price);}
    
    /*static*/ void run(){//non static funtions cannot override static functions
        super.run();//doesnt work for static functions
        //vehicle.run();
        System.out.println("Bike is running");
    }

    void disp(){
        super.disp();
        getBrand();
        getPrice();
    }
}
