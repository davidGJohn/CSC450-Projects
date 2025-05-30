#include <iostream>

using namespace std;

int main() {
    int* ptr1 = nullptr;
    int* ptr2 = nullptr;
    int* ptr3 = nullptr;

    ptr1 = new int;
    ptr2 = new int;
    ptr3 = new int;

    cout << "Enter first integer: ";
    cin >> *ptr1;

    cout << "Enter second integer: ";
    cin >> *ptr2;

    cout << "Enter third integer: ";
    cin >> *ptr3;

    cout << "\nValues entered:" << endl;
    cout << "First value (direct): " << *ptr1 << ", address: " << ptr1 << endl;
    cout << "Second value (direct): " << *ptr2 << ", address: " << ptr2 << endl;
    cout << "Third value (direct): " << *ptr3 << ", address: " << ptr3 << endl;
    
    delete ptr1;
    delete ptr2;
    delete ptr3;

    // For saftey
    ptr1 = ptr2 = ptr3 = nullptr;

    return 0;
}
