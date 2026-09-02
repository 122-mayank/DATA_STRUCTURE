#include<bits/stdc++.h>
using namespace std;

int main(){

    int num;
    cout <<"Enter the number"<< endl;
    cin >> num;

    for(int row = 1 ; row <= num; row++){

        // Technique 1

        // //space
        // for(int col = 1 ; col <= ( num - row + 1) ; col++){
        //     cout <<"  ";
        // }

        // //pattern
        // for(int col = 1 ; col <= (2 * (row - 1) + 1) ; col++){
        //     cout << "* ";
        // }

        // Technique 2 

        // for(int col = 1; col <= (num - row); col++) {
        // cout <<"  ";
        // }
        // for(int col = 1; col <= (2 * row - 1); col++) {
        // cout << "* ";
        // }

        cout << endl;

    }

}