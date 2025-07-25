#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    int age = 20;
    cout<<"age"<<endl;
    age=22;
    int a=15 , b=7;
    cout<<a+b<<endl<<a*b<<endl<<a/b<<endl;

    float note=15.5;
    double temperature=-4.2;
    double somme = note + temperature;
    cout<<endl<<somme<<endl;
    note=2*note;
    cout<<note;

    char lettre = 'A';
    cout<<endl<<lettre<<endl;
    lettre='Z';
    cout<<lettre<<endl;

    bool estMajeur=true;
    cout<<endl<<estMajeur<<endl;
    estMajeur=false;
    cout<<estMajeur<<endl;

    return 0;

}