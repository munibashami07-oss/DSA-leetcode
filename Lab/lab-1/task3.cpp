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

    Car* c1 = new Car("Toyota", "Corolla");
    Car* c2 = new Car("Honda", "Civic");

    c1->display();
    c2->display();

    delete c1;
    delete c2;

    return 0;
}