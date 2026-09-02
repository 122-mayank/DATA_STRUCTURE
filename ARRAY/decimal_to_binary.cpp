#include<bits/stdc++.h>
using namespace std;

int main(){

    int number;
    cout <<"Enter the number"<< endl;
    cin >> number;

    int temp = number;
    int ans = 0;
    int mul = 1;
    while(temp != 0){

        int rem = temp & 1;
        temp = temp >> 1;
        ans =  rem * mul + ans;
        mul = mul * 10;
    }
    cout << ans << endl;
}