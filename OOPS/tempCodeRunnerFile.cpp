
// Diamond Problem in c++

#include<bits/stdc++.h>
using namespace std;

class A{

      public:

      int marks;
      string name;

      A(string name, int marks):name(name) , marks(marks){
        cout<<"A constructor is called !!"<< endl;
      }

      ~A(){
            cout <<"A destructor is called!!"<< endl;
      }

};

class B : virtual public A{

      public:
      int roll_no;

      B(int roll_no):roll_no(roll_no){
            cout << "B constructor is called !!"<< endl;
      }

      ~B(){
            cout <<"B Destructor is called!!" << endl;
      }

};


class C : virtual public A{

      public:
      string subjects;

      C(string subjects):subjects(subjects){
            cout <<"C constructor is called !!"<< endl;
      }

      ~C(){
            cout << "C destructor is called !!"<< endl;
      }

};

class D : public B , public C{

      public:

      string section;

      D(string name, int age , string subjects , string section , int roll_no):
      B(roll_no) , C(subjects) , A(name  , age) , section(section){
         cout <<"D constructor is called!!"<< endl;
      }
      ~D(){
            cout <<"D destructor is called!!"<< endl;
      }

};

int main(){

      A* obj4 = new D("Rahul" , 23 , "DAA" , "FA" ,14);

      cout <<"Marks: "<< obj4->marks << endl;

      cout <<"Name: "<< obj4 ->name << endl;



}