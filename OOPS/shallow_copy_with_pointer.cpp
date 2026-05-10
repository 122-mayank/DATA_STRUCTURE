#include<bits/stdc++.h>
using namespace std;

class A{

    public:
    int *data;

    A(int val){
         data = new int;
         *data = val;
    }
    
    //Shallow Constructor
    A(const A &obj){
         data = obj.data;
    }

    void show(){
        cout << *data << endl;
    }
};

int main(){

    A obj(10);

    A obj2 = obj; //copy constructor

    *obj2.data = 20;

    obj.show();
    obj2.show();
}