public class vehicle extends vehicleMaker{
    String powerSource,colour;int noOfWheels,speed,regNo;
    static int registrationNo=0000;
    static final String countryCode="Ind";

    vehicle(String powerSource,String colour,int noOfWheels,int speed){
        this.noOfWheels=noOfWheels;
        this.powerSource=powerSource;
        this.colour=colour;
        this.speed=speed;
        regNo=++registrationNo;
    }
    
    void getNoOfWheels(){System.out.println("No of wheels is "+noOfWheels);}
     
    void getPowerSource(){ System.out.println("Power source is "+powerSource);}
    
    /*static*/void run(){System.out.println("Vehicle is fueled and ready to run");}
    
    void disp(){
        System.out.println("Country code is "+countryCode+" registration number is "+regNo);
        getPowerSource();
        System.out.println("Colour is "+colour);
        System.out.println("Speed is "+speed);
        getNoOfWheels();
    }
}
