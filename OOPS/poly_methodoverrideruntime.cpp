#include<bits/stdc++.h>
using namespace std;

class Animal{

     public:

     virtual void name() = 0;

     void eat(){
         cout <<"Animal is eating"<< endl;
     }

     virtual ~Animal(){
         cout <<"Animal destructor is called!!"<< endl;
     }


};

class Dog : public Animal{

    public:
    string value;

    Dog(string value){
         this -> value = value;
    }

    void name() override {
         cout << value <<" is called !! "<< endl;
    }
    ~Dog(){
        cout <<"Dog destructor is called!!"<< endl;
    }

};

class Cat : public Animal{

     public:
     string value;

     Cat(string value){
         this -> value = value;
     }

     void name() override{
         cout << value <<" is called !! "<< endl;
     }

     ~Cat(){
        cout <<"Cat destructor is called!!"<< endl;
     }
};

int main(){

    Animal* a ;
    a = new Dog("Bulldog");
    a ->name();
    a->eat();

    delete a;

    a = new Cat("Ragdoll");
    a->name();
    a->eat();

    delete a;

}