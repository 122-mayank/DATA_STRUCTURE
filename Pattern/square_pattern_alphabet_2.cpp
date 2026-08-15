#include<bits/stdc++.h>
using namespace std;
/*
 a b c d e 
 a b c d e 
 a b c d e 
 a b c d e
 a b c d e
*/

int main(){

    int n;
    cout <<"Enter the number "<< endl;
    cin >> n;


    for(int i = 1 ; i <= n ; i++){

        char ch = 'a';
        for(int j = 1 ; j <= n ; j++){
            
            cout << char(ch + j - 1) <<" ";

        }

        cout << endl;

    }

}