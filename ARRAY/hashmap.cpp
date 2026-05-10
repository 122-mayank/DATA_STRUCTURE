#include<bits/stdc++.h>
using namespace std;

int main(){

   //creation
    unordered_map<string , int > mp;
   
    //insertion
    pair<string,int> p = make_pair("radha" , 3);
    mp.insert(p);

    pair<string,int> pair2("Krishna" , 2);
    mp.insert(pair2);

    mp["govind"] = 4;

    for(auto i : mp){
          cout << "Key: " << i.first << " , Value: " << i.second << endl;
    }
     

    //search
    cout << mp["govind"] << endl;
    cout << mp.at("radha") << endl;

    // cout << mp.at("unknown") << endl;
    cout << mp["unknown"] << endl;
      cout << mp.at("unknown") << endl;        
      
      
      //size;
      cout <<"Size: "<< mp.size() << endl;

      //to check presence
      cout << mp.count("radha") << endl;


      //to erase the data
     mp.erase("govind");
     cout << "size: " << mp.size() << endl;

     //iterator
     unordered_map<string , int> :: iterator it = mp.begin();
     
     while(it != mp.end()){
           cout << it->first << " " << it->second << endl;
           it++;
     }


}