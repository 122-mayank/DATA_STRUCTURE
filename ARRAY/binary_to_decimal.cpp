#include<bits/stdc++.h>
using namespace std;

int main(){

    int num;
    cout <<"Enter the number"<< endl;
    cin >> num;

    int ans = 0;
    int i = 1;

    while(num != 0){        
        int rem = num % 10;
        num = num / 10;

        ans = rem * i + ans;
        i = i * 2;
    }

    cout << ans <<" "<< endl;

}