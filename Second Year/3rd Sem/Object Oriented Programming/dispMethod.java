class dispMethod{
    static void disp(int a, int b){
        System.out.println("two int are"+a+b);
    }

    static void disp(int a, int b, int c){
        System.out.println("3 integers are"+a+b+c);
    }

    static void disp(double a,double c){
        System.out.println("2 doubles are "+a+c);
    }
    public static void main(String []args){
        dispMethod.disp(1,2);
        dispMethod.disp(3,5);
        dispmethod.disp(3.5F,5.2F);

    }
}
