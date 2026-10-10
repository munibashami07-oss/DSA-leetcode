#include <iostream>
using namespace std;
int findMaximum(int arr[], int n) {
    if (n <= 0) {
        cout << "Array is empty." << endl;
        return -1;
    }
    int maximum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }
    return maximum;
}
int main() {
    int arr[] = {12, 45, 7, 89, 23};
    int n = 5;

    cout << "Maximum value: " << findMaximum(arr, n);
}