public class run{
    public static void main(String []args){
        Student s=new Student();
        Student s1=new Student(9165,19);
        Student s2=new Student("Jordan",9165,19);
        s.getData();
        s1.getData();
        s2.getData();
    }
}
/*
Name is , roll no is 0, age is 0
Name is , roll no is 9165, age is 19
Name is Jordan, roll no is 9165, age is 19
*/
