
// abstract class 
#include<bits/stdc++.h>
using namespace std;


class Shape{

      public:

      Shape(){
            cout <<"Shape Constructor is called !!"<< endl;
      }

        void info(){
        cout<<"This is a shape"<<endl;
    }

      virtual void draw() =0;

       virtual ~Shape(){
        cout<<"Shape destructor"<<endl;
    }
};

void Shape::draw(){
    cout<<"Default draw of shape"<<endl;
}

class Circle : public Shape{

      public:
      
      void draw(){
             cout <<"circle is drawing!!"<< endl;
      }
       ~Circle(){
        cout<<"Circle destructor"<<endl;
    }

};

class Square : public Shape{

      public:
      void draw(){
            cout <<"Square is drawing!!"<< endl;
      }
       ~Square(){
        cout<<"Square destructor"<<endl;
    }

};

int main(){

      Shape* a = new Square();
       a->draw();

       a->info();
       
       delete a;
}






















// method overriding  -> runtime polymorphism


// #include<bits/stdc++.h>
// using namespace std;

// class Animal{

//       public:
//       virtual void sound(){
//             cout <<"Animal makes sound!!"<< endl;
//       }
// };


// class Dog : public Animal{

//       public:
//        void sound() override{
//         cout<<"Dog barks"<<endl;
//     }
// };


// int main(){

//     Animal* a = new Dog();

//     a ->sound();


// }



// // polymorphism --> operator Overloading

// #include<bits/stdc++.h>
// using namespace std;

// class Complex{

//       public:
//       int real , imag;

//       Complex(int real , int imag){
//              this -> real = real;
//              this -> imag = imag;
//       }

//       Complex operator +(Complex c){
            
//             Complex temp(0,0);
//             temp.real = real + c.real;
//             temp.imag = imag + c.imag;

//             return temp;
//       }


// };

// int main(){

//     Complex c1(2,3);
//     Complex c2(4,5);

//     Complex c3 = c1 + c2;

//     cout<<"Real: "<<c3.real<<endl;
//     cout<<"Imaginary: "<<c3.imag;

// }