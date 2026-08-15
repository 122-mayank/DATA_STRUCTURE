#include<iostream>
using namespace std;

/*
 a a a a a 
 b b b b b
 c c c c c
 d d d d d
 e e e e e 
*/

int main(){

    int n;
    cout <<"Enter the number "<< endl;
    cin >> n;

    char ch = 'a';

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
             cout << ch <<" ";
        }
        cout << endl;
        ch = ch + 1;
    }

}