#include <iostream>
using namespace std;
int main() {

    int* arr = new int[5];

    cout << "Enter 5 integers: ";

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    cout << "Values: ";

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    delete[] arr;
}