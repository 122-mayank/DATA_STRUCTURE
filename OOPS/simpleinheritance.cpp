#include<iostream>
using namespace std;

class Animal{
      
    public:
    int age;
    int weight;


    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};

class dog: public Animal{
    
};

int main(){

dog d;
d.speak();
cout << d.age <<endl;





    return 0;
}