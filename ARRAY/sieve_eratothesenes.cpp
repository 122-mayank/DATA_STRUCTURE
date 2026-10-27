#include<bits/stdc++.h>
using namespace std;

int main(){

    int num;
    cout <<"Enter the num"<< endl;
    cin >> num;

    vector<int>isPrime(num + 1 , true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2 ; i * i <= num ; i++){
         if(isPrime[i]){
            for(int j = i * i ; j <= num ; j = j + i){
                 isPrime[j] = false;
            }
         }
    }

    //count the primes
    for(int i = 0 ; i < isPrime.size() ; i++){
        if(isPrime[i]){
            cout << i <<" ";
        }
    }



}