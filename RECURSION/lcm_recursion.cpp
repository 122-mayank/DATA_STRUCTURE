#include<iostream>
using namespace std;

int findLCM(int a, int b, int current) {
    if (current % a == 0 && current % b == 0)
        return current; // Found LCM
    return findLCM(a, b, current + 1); // Check next number
}

int main(){

int a , b;
cout <<"Enter the two values: "<<endl;
cin >> a >> b;

cout << findLCM( a , b ,max(a,b)) << endl;



}