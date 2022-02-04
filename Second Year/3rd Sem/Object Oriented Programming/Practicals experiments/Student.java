public class Student{
    String name;int age,roll_no;
    static String coll;
   
    static{

	coll="CRCE";

    }

    Student(){
        age=0;
        roll_no=0;
        name="<no name specified>";
    }
    
    Student(String name){
        this(9156,23);
        this.name=name;
    }
    
    Student(int roll_no,int age){
        name="<no name specified>";
        this.age=age;
 	this.roll_no=roll_no;
    }
    
    Student(String name,int roll_no,int age){
        this.age=age;
        this.roll_no=roll_no;
        this.name=name;
    }
    
    String toString(){

        return "name is "+name+", roll number is "+roll_no+", age is "+age"\ncollege is "+coll;

    }
}