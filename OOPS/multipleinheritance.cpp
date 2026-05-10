#include<iostream>
using namespace std;

class Animal{
      
    public:
    int age;
    int weight;


    public:
    void bark(){
        cout<<"Barking"<<endl;
    }
};

class human{

    public:
    string color ;

    public:
    void speak(){
        cout <<"Speaking"<<endl;
    }

};

class Hybrid : public Animal , public human{

};


int main(){

Hybrid obj1;
obj1.speak();
obj1.bark();




    return 0;
}