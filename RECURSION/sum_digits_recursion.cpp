#include<iostream>
using namespace std;

int solve( int num){

if( num == 0){
    return 0;
}  
return (num % 10) + solve( num / 10);

}

int main(){

int n;

cout <<"Enter the number: "<<endl;
cin >> n;

cout << solve(n);

}