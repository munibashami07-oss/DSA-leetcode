#include <iostream>
using namespace std;

class Heap {
    int arr[100];
    int n;

public:
    Heap() {
        n = 0;
    }

    void insert(int x) {
        arr[n++] = x;
    }

    void selectionSort() {
        for (int i = 0; i < n ; i++) {
            int minIndex = i;

            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            swap(arr[i], arr[minIndex]);
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;

    h.insert(50);
    h.insert(20);
    h.insert(40);
    h.insert(10);
    h.insert(30);

    cout << "Before sorting: ";
    h.display();

    h.selectionSort();

    cout << "After sorting: ";
    h.display();

    return 0;
}