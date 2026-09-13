#include<bits/stdc++.h>
using namespace std;

int main(){

    int num;
    cout << "Enter the num "<< endl;
    cin >> num;


    int cnt = 0;

    for(int i = 1 ; i * i <= num ; i++){

        if( num % i == 0){

            cnt= cnt + 1;

            if((num / i) != i){
                cnt = cnt + 1;
            }
        }

    }

    if(cnt == 2){
        cout << num <<" is prime "<< endl;
    }
    else{
        cout << num <<" is not prime "<< endl;
    }

}