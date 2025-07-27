#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


/*
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

*/

void incremete(int *p)
{
    (*p)+=1;
}

void swap(int *a , int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int main()
{
 int a = 10;
 int *ptr= &a;
 cout<<ptr<<endl<<*ptr;

 *ptr=20;
 cout<<endl<<a<<endl;

 int x = 10;
 int y=20;
 int *ptrx=&x;
 int *ptry=&y;
 cout<<endl<<endl<<*ptrx+*ptry<<endl;

 incremete(&x);
 cout<<endl<<*ptrx;

swap(&x , &y);

cout<<endl<<endl<<*ptrx<<*ptry<<endl;


 return 0;
}