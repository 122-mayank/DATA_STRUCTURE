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

class germansphered : public dog{

};

int main(){

germansphered g;
g.speak();





    return 0;
}