#include<bits/stdc++.h>
using namespace std;

void printDivisors(int n){

    vector<int>ls;

    for(int i = 1 ; i <= sqrt(n) ;  i++){

        if( n % i == 0){
            ls.push_back(i);

            if((n / i ) != i){
                  ls.push_back(n / i);
            }
        }

    }

    sort(ls.begin() , ls.end());
    for(auto it : ls) cout << it <<" ";

}

int main(){

    int num;
    cout <<"Enter the num"<< endl;
    cin >> num;

    printDivisors(num);

    cout << endl;

    for(int i = 1 ; i <= num ; i++){
         if(num % i == 0){
             cout << i <<" ";
         }
    }

}