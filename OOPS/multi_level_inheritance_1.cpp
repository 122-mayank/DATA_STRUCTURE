#include<bits/stdc++.h>
using namespace std;

class Animal{
  public:
  string name;
  
  Animal(string n){
     name = n;
     cout <<"Animal constructor is called!!"<< endl;
  }

  void eat(){
    cout << name <<" is eating"<< endl;
  }
};

class Dog : public Animal{

    public:
    Dog(string n):Animal(n){
         cout <<"Dog constructor is called"<< endl;
    }

    void bark(){
        cout << name <<" is barking"<< endl;
    }

};

class Puppy : public Dog{
    public:

    Puppy(string n) : Dog(n){
         cout <<"Puppy constructor is called !!"<< endl;
    }

    void play(){
        cout << name <<" is playing "<< endl;
    }
};



int main(){

    Puppy p("Tommy");

    cout << endl;

    p.eat();
    p.bark();
    p.play();
    
}