#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    float price;

public:
    // Constructor
    Product(int i, string n, float p)
        : id(i), name(n), price(p)
    {
        cout << "Constructor called for product: " << name << endl;
    }

    // Destructor
    ~Product() {
        cout << "Destructor called for product: " << name << endl;
    }

    // Method to print details
    void printDetails() {
        cout << "ID: " << id 
             << ", Name: " << name 
             << ", Price: $" << price 
             << endl;
    }
};

int main() {
    // Create product object
    Product p(101, "Notebook", 4.99);

    // Call method to verify functionality
    p.printDetails();

    return 0;
}
