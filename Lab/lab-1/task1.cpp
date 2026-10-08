#include <iostream>
using namespace std;
class Car {
public:
    string brand;
    string model;

    Car(string b, string m) {
        brand = b;
        model = m;
    }

    void display() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }
};
int main() {

    Car c1("Toyota", "Corolla");

    c1.display();
}