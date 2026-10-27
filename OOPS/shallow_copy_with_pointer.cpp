
#include <bits/stdc++.h>
using namespace std;

class Demo {
public:
    int* x;

    Demo(int val) {
        x = new int(val);
    }

    // Copy Constructor (Shallow Copy)
    Demo(const Demo &d) {
        x = d.x;  // Copies the address
    }
};

int main() {
    Demo d1(10);
    Demo d2 = d1;  // Shallow copy

    *d2.x = 20;

    cout << "d1.x: " << *d1.x << endl;
    cout << "d2.x: " << *d2.x << endl;

    return 0;
}
