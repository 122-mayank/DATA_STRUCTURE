#include<iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Insert elements (only 0, 1, 2): " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int low = 0, mid = 0, high = size - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}
