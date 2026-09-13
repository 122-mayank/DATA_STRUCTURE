#include<bits/stdc++.h>
using namespace std;

int main(){

    int a , b;
    cout <<"Enter the number a and b"<< endl;
    cin >> a >> b;


    while(b != 0){

        int remainder = a % b;
        a = b;
        b = remainder;

    }

    cout << "HCF : "<< a << endl;

}