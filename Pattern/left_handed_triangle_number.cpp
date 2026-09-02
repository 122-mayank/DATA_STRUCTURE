#include<iostream>
using namespace std;

int main(){

    int num;
    cout <<"Enter the number:"<< endl;
    cin >> num;

    for(int row = 1 ; row <= num ;row++){

        //space
        for(int col = 1 ; col <= (num - row) ; col++)
             cout <<"  ";
        //pattern
        for(int col = (row - 1 + 1) ; col >= 1 ; col--)
            cout << col <<" ";

        cout << endl;    
    }

}