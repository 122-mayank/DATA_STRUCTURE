#include<bits/stdc++.h>
using namespace std;

class Stack{

    public:

    vector<int> arr;

    int size;
    int top;

    Stack(int size){

        this->size = size;

        top = -1;

        arr.resize(size);
    }

    void push(){

        if(top == size-1){

            cout<<"Stack Overflow"<<endl;
            return;
        }

        int data;

        cout<<"Enter data"<<endl;
        cin>>data;

        top++;

        arr[top] = data;
    }

    int pop(){

        if(top == -1){

            cout<<"Stack Underflow"<<endl;
            return -1;
        }

        int value = arr[top];

        top--;

        return value;
    }

    void display(){

        if(top == -1){

            cout<<"Stack Empty"<<endl;
            return;
        }

        cout<<"Stack:"<<endl;

        for(int i=top;i>=0;i--){

            cout<<arr[i]<<" ";
        }

        cout<<endl;
    }
};

int main(){

    int size;

    cout<<"Enter stack size"<<endl;
    cin>>size;

    Stack obj(size);

    int choice;

    while(true){

        cout<<"\nEnter the choice"<< endl;

        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;

        cin>>choice;

        switch(choice){

            case 1:
                obj.push();
                break;

            case 2:{

                int value = obj.pop();

                if(value != -1){

                    cout<<"Popped Value: "
                        <<value<<endl;
                }

                break;
            }

            case 3:
                obj.display();
                break;

            case 4:
                exit(0);

            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
}