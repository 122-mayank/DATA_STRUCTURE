#include<bits/stdc++.h>
using namespace std;

/*
     *
    **
   ***
  ****
 ***** 
*/

int main(){


    int num;
    cout <<"Enter the number "<< endl;
    cin >> num;

    for(int row = 1; row <= num ; row++){
        //space
        for(int col = 1 ; col <= (num - row) ; col++){
             cout <<"  ";
        }
        //star
        for(int col = 1 ; col <= row ; col++){
               cout << "* ";
        }

        cout << endl;

    }

}