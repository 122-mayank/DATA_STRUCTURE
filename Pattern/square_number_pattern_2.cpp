#include<iostream>
using namespace std;

/*
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
*/

int main(){

    int n;
    cout <<"Enter the number "<< endl;
    cin >> n;

    for(int row = 1; row <= n ; row++){
         for(int col = 1 ; col <= n; col++){
            cout << n - col + 1 <<" ";
         }
         cout << endl;
    }

}