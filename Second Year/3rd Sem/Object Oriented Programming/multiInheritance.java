
class a{
    a(){
        this(5);
        System.out.println("constructor of a");
    }
    a(int n){System.out.println("parameterized constructor of a");}
    void A(){System.out.println("A");}
    void overload(){System.out.println("overload in superclass a");}
}

class b extends a{
    b(){
        super();
        System.out.println("constructor of b");
    }
    
    b(int a){System.out.println("parameterized constructor in b");}
    void B(){System.out.println("B");}
}

class c extends b{
    c(){System.out.println("constructor of c");}
    void C(){System.out.println("C");}
}

class d extends a{
    d(){System.out.println("constructor for d");}
    void D(){System.out.println("D");}
    void overload(){System.out.println("overload in base class d");}
    void main(){
        System.out.println("Calling from class d");
        overload();
        super.overload();
    }
}

public class multiInheritance{
    public static void main(){
        System.out.println("object of b extends a");
        b ob1=new b();
        ob1.B();
        ob1.A();
        System.out.println("object of c extends b");
        c ob2=new c();
        ob2.C();
        ob2.B();
        ob2.A();
        System.out.println("object of d exends a");
        d ob3=new d();
        ob3.D();
        ob3.A();
        ob3.overload();
        ob3.main();
    }
}
