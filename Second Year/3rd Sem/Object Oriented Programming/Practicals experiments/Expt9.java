class student{

    String branch;

    
    void getData(String branch){

        this.branch=branch;

    }

    void printData(){

        System.out.println("Branch is "+branch);

    }

}

class UG_Student extends student{

    String s_class;

    
    void getData(String branch,String s_class){

        super.getData(branch);

        this.s_class=s_class;

    }

    void printData(){

        super.printData();

        System.out.println("class is "+s_class);

    }
}

public class Expt9{
    public static void main(String []args){

        UG_Student student1=new UG_Student();

        student1.getData("ECS","SE");

        student1.printData();

    }
}