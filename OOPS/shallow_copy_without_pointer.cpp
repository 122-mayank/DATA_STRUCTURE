#include<bits/stdc++.h>
using namespace std;

class Demo{
public:

    int x;

    Demo(int val){
        x = val;
    }

    //Copy Constructor(Shallow Copy)
    Demo(const Demo &d){
        x = d.x;
    }
};

int main(){

    Demo d1(10);
    Demo d2 = d1;   //copy constructor

    d2.x = 20;

    cout <<"d1.x: "<< d1.x << endl; //10
    cout <<"d2.x: "<< d2.x << endl; //20


}