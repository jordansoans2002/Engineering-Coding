#include <iostream>
using namespace std;

class A{
    private:
    int a=5;
    friend class B;
};

class B{
    public:
        void print(A a){//able to access private value of A
            printf("value of a is: %d",a);
        }
};

int main(){
    A a;
    B b;
    b.print(a);
}
