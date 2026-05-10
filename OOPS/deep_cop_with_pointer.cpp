#include<bits/stdc++.h>
using namespace std;

class Demo{

    public:
    int *data;

   //Copy Constructor
    Demo(int val){
        data = new int;
        *data = val;
    }

    //Deep Copy Constructor
    Demo(const Demo &d){
        data = new int;
        *data = *(d.data);
    }

    void show(){
        cout << *data << endl;
    }


};

int main(){

    Demo d1(10);

    Demo d2 = d1;

    *d2.data = 20;

    d1.show();
    d2.show();
}