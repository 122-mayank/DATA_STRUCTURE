#include<bits/stdc++.h>
using namespace std;

class A {
public:
    string name;

    A(string name) : name(name) {
        cout << "A constructor is called!!" << endl;
    }

    ~A() {
        cout << "A destructor is called!!" << endl;
    }
};

class B : virtual public A {
public:
    int age;

    // ❌ Do NOT call A(name) here
    B(int age) : A("dummy"), age(age) {
        cout << "B constructor is called!!" << endl;
    }

    ~B() {
        cout << "B destructor is called!!" << endl;
    }
};

class C : virtual public A {
public:
    int rollno;

    // ❌ Do NOT call A(name)
    C(int rollno) : A("dummy"), rollno(rollno) {
        cout << "C constructor is called!!" << endl;
    }

    ~C() {
        cout << "C destructor is called!!" << endl;
    }
};

class D : public B, public C {
public:
    int marks;

    // ✅ ONLY D initializes virtual base A
    D(string name, int rollno, int age, int marks)
        : A(name), B(age), C(rollno), marks(marks)
    {
        cout << "D constructor is called!!" << endl;
    }

    ~D() {
        cout << "D destructor is called!!" << endl;
    }
};

int main() {

    D* d = new D("Krishna", 56, 21, 99);

    cout << d->name << " "
         << d->age << " "
         << d->rollno << " "
         << d->marks << endl;

    delete d;
}
















// // hierarchical inheritance

// #include<bits/stdc++.h>
// using namespace std;

// class Animal{
// protected:
//     string name;

// public:
//     Animal(string name) : name(name){
//         cout << "Animal Constructor\n";
//     }

//   virtual ~Animal(){
//         cout << "Animal Destructor\n";
//     }

//     void eat(){
//         cout << name << " is eating\n";
//     }
// };


// // Child 1
// class Dog : public Animal{

// public:
//     Dog(string name) : Animal(name){
//         cout << "Dog Constructor\n";
//     }

//     ~Dog(){
//         cout << "Dog Destructor\n";
//     }

//     void bark(){
//         cout <<  name << " is barking\n";
//     }
// };


// // Child 2
// class Cat : public Animal{
// public:
//     Cat(string name) : Animal(name){
//         cout << "Cat Constructor\n";
//     }

//     ~Cat(){
//         cout << "Cat Destructor\n";
//     }

//     void meow(){
//         cout << name << " is meowing\n";
//     }
// };


// int main(){

//     Animal* a = new Dog("pitbull");
//     a->eat();


// }







// multiple inheritance

// #include<bits/stdc++.h>
// using namespace std;

// class Person{
// protected:
//     string name;

// public:
//     Person(string name) : name(name){
//         cout << "Person Constructor\n";
//     }

//     virtual ~Person(){
//         cout << "Person Destructor\n";
//     }

//     void showPerson(){
//         cout << "Name: " << name << endl;
//     }
// };

// class Student{
// protected:
//     int roll;

// public:
//     Student(int roll) : roll(roll){
//         cout << "Student Constructor\n";
//     }

//     virtual ~Student(){
//         cout << "Student Destructor\n";
//     }

//     void showRoll(){
//         cout << "Roll: " << roll << endl;
//     }
// };

// class CollegeStudent : public Person, public Student{
// private:
//     string college;

// public:
//     // call BOTH base constructors
//     CollegeStudent(string name, int roll, string college)
//         : Person(name), Student(roll), college(college)
//     {
//         cout << "CollegeStudent Constructor\n";
//     }

//     ~CollegeStudent(){
//         cout << "CollegeStudent Destructor\n";
//     }

//     void showAll(){
//         showPerson();
//         showRoll();
//         cout << "College: " << college << endl;
//     }
// };

// int main(){

//     CollegeStudent obj("Rohit", 101, "IIT Delhi");

//     obj.showAll();
// }





// #include<bits/stdc++.h>
// using namespace std;

// class College{
// public:
//     College(){
//         cout << "College Constructor\n";
//     }

//     virtual ~College(){   // ⭐ VERY IMPORTANT (virtual)
//         cout << "College Destructor\n";
//     }
// };

// class Student : public College{
// public:
//     Student(){
//         cout << "Student Constructor\n";
//     }

//     ~Student(){
//         cout << "Student Destructor\n";
//     }
// };

// class Course : public Student{
// public:
//     Course(){
//         cout << "Course Constructor\n";
//     }

//     ~Course(){
//         cout << "Course Destructor\n";
//     }
// };

// int main(){

//     College* ptr = new Course();

//     delete ptr;
// }
















// inheritance - multilevel inheritance

// #include<bits/stdc++.h>
// using namespace std;

// class College{

//     public:
//     string name;

//     College(string name):name(name){}

//     void CollegeName(){
//              cout << name <<" is called !!"<< endl;
//     }

// };

// class Student : public College{

//     public:
//     string sname;

//     Student(string collegeName , string sname):College(collegeName),sname(sname){}

//     void studentName(){
//         cout << sname <<" is called !! "<< endl;
//     }

// };

// class Course : public Student{

//     public:
//     string cname;

//     Course(string collegeName , string studentName , string cname):
//     Student(collegeName,studentName),cname(cname){}

//     void CourseName(){
//         cout << cname << " is assigned to student !! "<< endl;
//     }

// };

// int main(){

//     Course*ptr = new Student("Axis","Rohit");
//     cout << ptr -> name << endl;

// }






// inheritance example - simple inheritance
// #include<bits/stdc++.h>
// using namespace std;

// class Animal{

//     public:

//     void eat(){
//          cout <<"Animal is eating!!"<< endl;
//     }

// };

// class Dog : public Animal{

//     public:
//     void bark(){
//         cout <<"Dog is Barking!!"<<endl;
//     }

// };

// int main(){

//     Animal* a = new Dog();

//     a->bark();
//     a->eat();


// }
