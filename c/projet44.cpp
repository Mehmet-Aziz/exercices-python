#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main() {
    int age = 20;
    int *ptr = &age; // ptr pointe vers age

    cout << "Valeur de age: " << age << endl;
    cout << "Adresse de age: " << &age << endl;
    cout << "Valeur de ptr (adresse): " << ptr << endl;
    cout << "Valeur pointee par ptr: " << *ptr << endl;

    *ptr = 42; // change age via le pointeur
    cout << "Nouvelle valeur de age: " << age << endl;
    return 0;
}