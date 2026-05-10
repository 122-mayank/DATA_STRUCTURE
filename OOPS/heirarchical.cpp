#include<iostream>
using namespace std;

class A{

    public:
    void fun(){
        cout <<"Inside function 1" <<endl;
    }
};

class B: public A{
    public:
    void fun2(){
        cout<<"Inside function 2"<<endl;
    }
};

class C:public A{
        public:
        void fun3(){
            cout<<"inside function 3"<<endl;
        }
};

int main(){

A object1;
object1.fun();

B object2 ;
object2.fun();
object2.fun2();

C object3;
object3.fun();
object3.fun3();


    return 0;
}