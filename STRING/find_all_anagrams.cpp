#include<bits/stdc++.h>
using namespace std;

bool allZeroes(unordered_map<char , int>mp){

    for(auto it : mp){
        if(it.second != 0) return false; 
    }

    return true;

}

vector<int>findAnagrams(string s , string p){

    //count the frequency of pattern p

    unordered_map<char , int>mp;

    int m = s.size();
    int n = p.size();

    for(int i = 0 ; i < p.size() ; i++){
        mp[p[i]]++;
    }

    int i = 0;
    int j = 0;

    vector<int>ans;

    while(j < m){

        mp[s[j]]--;

        if(j - i + 1 == n){
            if(allZeroes(mp)){
                ans.push_back(i);
            }

            mp[s[i]]++;
            i++;
        }

        j++;

    }

    return ans;

}

int main(){

    string s;
    cout<<"Enter the text "<< endl;
    getline(cin ,s);

    string p;
    cout <<"Enter the pattern "<< endl;
    getline(cin , p);

    vector<int>ans = findAnagrams(s , p);

    //print the answer
    cout <<"Indices of anagrams"<< endl;
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] <<" ";
    }

}