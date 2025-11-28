#include <iostream>
using namespace std;

int main() {
    float n1, n2, n3;

    cout << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3;

    float largest = n1;

    if (n2 > largest)
        largest = n2;

    if (n3 > largest)
        largest = n3;

    cout << "Largest number: " << largest << endl;

    return 0;
}
