#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>&a , vector<int>&b){

    int n = a.size();
    int m = b.size();

    vector<int>temp;

    int i = 0 , j = 0;
    while( i < n && j < m){

        if(a[i] < b[j]){
            i++;
        }
        else if(a[i] > b[j]){
            j++;
        }
        else{
            temp.push_back(a[i]);
            i++;
            j++;
        }
        
    }
    return temp;
    
}

int main(){

    int size1;
    cout <<"Enter the size of first array"<< endl;
    cin >> size1;

    int size2;
    cout <<"Enter the size of second array"<< endl;
    cin >> size2;

    vector<int>a(size1);
    vector<int>b(size2);

    cout <<"Enter the elements of first array"<< endl;
    for(int i = 0 ; i < size1 ; i++){
        cin >> a[i];
    }

    cout <<"Enter the elements of second array"<< endl;
    for(int i = 0 ; i < size2 ; i++){
        cin >> b[i];
    }

    vector<int>ans = solve(a , b);

    cout <<"Intersection of two sorted array"<< endl;
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] <<" ";
    }
    
}