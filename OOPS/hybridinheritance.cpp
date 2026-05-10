#include<iostream>
using namespace std;

class A{

    public:
    int price;

    public:
    void model(){
        cout <<"Computer Science called !!"<<endl;
    }
};

class B : public A{

    public:
    int price;

    void model2(){
        cout <<"AI is called"<<endl;
    }
};
class D{
    public:
    void model4(){
        cout <<"Shyamsundar is calling to u"<<endl;
    }
};

class C : public A , public D{
    public:
    int price;

    void model3(){
        cout <<"Data science called"<<endl;
    }
};



int main(){

A obj1;
 obj1.model(); 

B obj2;
obj2.model();
obj2.model2();

C obj3;
obj3.model4();
obj3.model();




    return 0;
}