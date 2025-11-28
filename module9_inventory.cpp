#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int quantity;
};

int searchByName(Item items[], int size, string target) {
    for (int i = 0; i < size; i++) {
        if (items[i].name == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    const int SIZE = 5;
    Item inventory[SIZE];

    cout << "--- Enter item information ---" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << "Item " << i + 1 << " name: ";
        cin >> inventory[i].name;

        cout << "Quantity: ";
        cin >> inventory[i].quantity;
    }

    cout << "\n--- Inventory List ---" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << inventory[i].name << " - Quantity: " << inventory[i].quantity << endl;
    }

    string searchName;
    cout << "\nEnter item name to search: ";
    cin >> searchName;

    int index = searchByName(inventory, SIZE, searchName);

    if (index != -1) {
        cout << "Found " << searchName << " with quantity: " << inventory[index].quantity << endl;
    } else {
        cout << searchName << " not found in inventory." << endl;
    }

    return 0;
}
