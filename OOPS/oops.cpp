
//multilevel inheritance
#include<bits/stdc++.h>
using namespace std;

class A{

    public:
    void showA(){
         cout <<"A is called !!"<< endl;
    }

};

class B : public A{

    public:
    void showB(){
        cout <<"B is called !!"<< endl;
    }

};


class C : public B{

    public:

    void showC(){
         cout << "C is called !! " << endl;
    }

};

int main(){

    C obj = new C();

    obj->showA();
    obj->showB();


}