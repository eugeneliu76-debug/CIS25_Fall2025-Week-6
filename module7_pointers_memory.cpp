#include <iostream>
#include <string>
using namespace std;

// Struct definition
struct Item {
    string name;
    int id;
};

// Binary search by ID
int binarySearch(Item* arr, int size, int targetID) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid].id == targetID) {
            return mid; // found
        }
        else if (targetID < arr[mid].id) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1; // not found
}

int main() {

    int size = 100;

    // Dynamically allocate array
    Item* inventory = new Item[size];

    // Populate with sorted data id = 1..100
    for (int i = 0; i < size; i++) {
        inventory[i].id = i + 1;
        inventory[i].name = "Item_" + to_string(i + 1);
    }

    // Ask user for ID to search
    int searchID;
    cout << "Enter an ID to search (1 - 100): ";
    cin >> searchID;

    // Binary search
    int index = binarySearch(inventory, size, searchID);

    if (index != -1) {
        cout << "\nItem found!" << endl;
        cout << "Name: " << inventory[index].name << endl;
        cout << "ID: " << inventory[index].id << endl;
    } else {
        cout << "\nItem with ID " << searchID << " not found." << endl;
    }

    // Free dynamic memory
    delete[] inventory;

    return 0;
}
