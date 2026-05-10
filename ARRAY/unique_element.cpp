#include<iostream>
using namespace std;

int main(){

    int m;
    cout<<"Enter the m number: "<<endl;
    cin >> m;

    int n = 2*m + 1;
    int *arr = new int[n];

    cout<<"Insert the elements: "<<endl;
    for( int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int ans = 0;
    for( int i = 0 ; i < n ; i++){
        ans = ans^arr[i];
    }
   cout << ans <<endl;

}