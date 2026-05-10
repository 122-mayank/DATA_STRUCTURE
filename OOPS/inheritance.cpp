






































// // multilevel inheritance

// #include<bits/stdc++.h>
// using namespace std;

// class Animal{

//      public:
//      string name;

//      void eat(){
//         cout <<"Every animal is eating "<< endl;
//      }

// };


// class Dog : public Animal{

//      public:

//      void bark(){
//         cout <<"Dog is Barking "<< endl;
//      }
// };

// class BabyDog : public Dog{

//     public:

//     void walk(){
//         cout <<"Baby dog is walking "<< endl;
//     }

//     BabyDog(string name){
//         this -> name = name;
//     }

//     void display(){
//         cout << name <<" is baby of the dog"<< endl;
//     }

// };
// int main(){


//     BabyDog b("Pitbull");

//     b.display();
//     b.bark();
//     b.eat();



// }

































// // inheritance

// #include<bits/stdc++.h>
// using namespace std;

// class Vehicle{

//      public:
//      string  name;

//      void accelerate(){
//         cout <<"Vehicle has accelerated!"<< endl;
//      }

// };

// class Car : public Vehicle{

//     public:
//     void speed(){
//          cout <<"Car has more spped than bike: "<< endl;
//     }

//     Car(string car){
//        this -> name = car;
//     }

//     void display(){
//         cout << name <<" has latest model"<< endl;
//     }

// };




// int main(){

//      Car c("Bolero");
//      c.display();

//      c.speed();


// }