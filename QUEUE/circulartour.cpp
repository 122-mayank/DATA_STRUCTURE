#include<iostream>
using namespace std;

// Define the petrolPump structure
struct petrolPump {
    int petrol;
    int distance;
};

class Solution {
public:
    int tour(petrolPump p[], int n) {
        int deficit = 0;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            balance += p[i].petrol - p[i].distance;
            if (balance < 0) {
                deficit += balance;
                start = i + 1;
                balance = 0;
            }
        }

        if (deficit + balance >= 0) {
            return start;
        } else {
            return -1;
        }
    }
};

int main() {
    // Example input
    int n;
    cout << "Enter number of petrol pumps: ";
    cin >> n;

    petrolPump* arr = new petrolPump[n];

    cout << "Enter petrol and distance for each pump:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].petrol >> arr[i].distance;
    }

    Solution obj;
    int startIndex = obj.tour(arr, n);

    if (startIndex != -1)
        cout << "Start from petrol pump index: " << startIndex << endl;
    else
        cout << "No solution possible\n";

    delete[] arr;
    return 0;
}
