#include <iostream>
using namespace std;

int main() {
    const int CAPACITY = 10;
    int arr[CAPACITY] = {10, 20, 30, 40, 50};
    int n = 5;

    // Operation 1: Display initial array
    cout << "Operation 1: Initial Array\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Operation 2: Traverse array
    cout << "Operation 2: Traversal\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Operation 3: Search for an element
    int key = 30, index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }
    cout << "Operation 3: Search index = " << index << endl;

    // Operation 4: Insert at end
    arr[n++] = 60;
    cout << "Operation 4: Insert at end\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Operation 5: Insert at index 2
    int pos = 2, value = 25;
    if (n < CAPACITY && pos >= 0 && pos <= n) {
        for (int i = n; i > pos; i--)
            arr[i] = arr[i - 1];
        arr[pos] = value;
        n++;
    }
    cout << "Operation 5: Insert at index\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Operation 6: Delete at index 1
    pos = 1;
    if (pos >= 0 && pos < n) {
        for (int i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];
        n--;
    }
    cout << "Operation 6: Delete at index\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Operation 7: Update at index 0
    arr[0] = 99;
    cout << "Operation 7: Update\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}