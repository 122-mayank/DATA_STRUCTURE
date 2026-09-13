#include<bits/stdc++.h>
using namespace std;

int main(){

    int num1 , num2;
    cout <<"Enter the num1 and num2"<< endl;
    cin >> num1 >> num2;

    int gcd = 1;

    for(int i = 1 ; i <= max(num1 , num2) ; i++){
        if(num1 % i == 0 && num2 % i == 0){
            gcd = i;
        }
    }

    cout << "Gcd of "<< num1 <<" and "<< num2 << " is "<< gcd << endl;

}