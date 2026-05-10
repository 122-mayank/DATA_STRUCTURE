#include<iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size: " << endl;
    cin >> size;

    int *arr = new int[size];

    cout << "Insert elements (only 0 and 1): " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int i = 0;
    int j = size - 1;

    while (i < j) {
        // Move i forward if arr[i] is 0
        while (arr[i] == 0 && i < j) i++;
        // Move j backward if arr[j] is 1
        while (arr[j] == 1 && i < j) j--;

        // Swap if out-of-place 1 at i and 0 at j
        if (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}
