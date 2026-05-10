#include<iostream>
using namespace std;

int solve(int a , int b){
    //base case
    if( b == 0){
        return a;
    }

   return  solve(  b, a % b);
 
}

int main(){

 int a , b;
 cout <<"Enter the two values: ";
 cin >> a >>b;

 cout << solve(a,b) <<endl;



}