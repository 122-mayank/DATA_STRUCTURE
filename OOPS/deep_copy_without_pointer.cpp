#include<bits/stdc++.h>
using namespace std;

class Demo{

    public:
    int x;

    Demo(int val){
         x = val;
    }

    //Copy Constructor
    Demo(const Demo &d){
        x = d.x;
    }

    void show(){
        cout << x << endl;
    }
};


int main(){


    Demo d1(20);

    Demo d2 = d1;

    d2.x = 10;

    d1.show();
    d2.show();

}