#include<bits/stdc++.h>
using namespace std;

int main(){

    int row;
    cout <<"Enter the row"<< endl;
    cin >> row;

    int col;
    cout <<"Enter the col"<< endl;
    cin >> col;

    cout <<"Pattern"<< endl<< endl;
    for(int i = 1 ; i <= row ; i++){

        for(int k = 1 ; k < i ; k++){
             cout <<" ";
        }
        for(int j = col ; j >=i ; j--){
            cout <<"* ";
        }

        cout << endl;
    }

    for(int i = 2 ; i <= row ; i++){
        
        for(int k = col ; k > i ;k--){
             cout <<" ";
        }

        for(int j = 1 ; j <=i ; j++){
            cout <<"* ";
        }

        cout << endl;

    }


}