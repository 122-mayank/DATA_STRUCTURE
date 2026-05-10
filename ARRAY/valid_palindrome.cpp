#include<iostream>
using namespace std;

bool valid(char ch){

if( (ch >= 'a' && ch <='z') || (ch >= 'A' && ch <= 'Z') || ( ch >='0' && ch <= '9') ){
      return 1;
}
else{
    return 0;
}

}

char toLowerCase(char ch){

    if( ch >= 'a' && ch <='z') {
        return ch;
    }

    else{

         char temp = ch - 'A' + 'a';
         return temp;
    }

}

bool checkPalindrome(string temp){

    int st = 0;
    int end = temp.size() - 1;

    while( st < end){


        if( temp[st] != temp[end]){
            return 0;
        }
st++;
end--;
    }
    return 1;

}

bool isPalindrome(string s){

    string temp;

    for( int i = 0 ; i < s.size() ; i++){
          
        if(valid(s[i])){
            temp.push_back(s[i]);
        }
    }

    // changing to lowercase caharcter
   for( int i = 0 ; i < temp.size() ; i++){
            temp[i] = toLowerCase(temp[i]);
   }
    return checkPalindrome(temp);
}



int main(){

    string s;
    cout <<"Enter the String : "<<endl;
    cin >> s;

    bool ans = isPalindrome(s);
    if(ans){
         cout <<"String is Palindrome!!"<<endl;
    }

    else{
         cout <<"String is not Palindrome!!"<<endl;
    }



}