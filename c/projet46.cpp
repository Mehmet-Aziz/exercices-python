#include <iostream>
using namespace std;

void hello_world()
{
    cout<<"Hello, World !"<<endl;
}

void prenom()
{
    cout<<"tu t'apelle comment ?"<<endl;
    string prenom;
    cin>>prenom;
    cout<<"Salut"<<prenom<<endl;
}

void somme()
{
    float a , b;
    cout<<"donne moi deux nombres que je vais sommer"<<endl;
    cin>>a>>b;
    cout<<"la somme de "<<a<<"+"<<b<<"= "<<a+b<<endl;
}


void moyenne()
{
    float a , b;
    cout<<"donne moi deux nombres que je vais moyenner"<<endl;
    cin>>a>>b;
    cout<<"la moyenne de "<<a<<" et "<<b<<"= "<<(a+b)/2<<endl;
}

void km_to_miles()
{
    cout<<"combien de km tu dois convertir ?"<<endl;
    float miles;
    cin>>miles;
    miles=miles*0.621371;
    cout<<"tu as "<<miles <<" en miles"<<endl;
}

void surface_rectangle()
{
    float longueur , largeur;
    cout<<"quelle est la longueur et lageur du rectangle ?"<<endl;
    cin>>longueur>>largeur;
    cout<<"voici les dimensions , en longueur on a : "<<longueur<<"et e, largeur : "<<largeur<<endl;
}

void perimetre_cercle()
{
const int pi=3.14;
float r;
cout<<"pour calculer le perimetre du cercle donner moi son rayon"<<endl;
cin>>r;
cout<<"voici le perimetre : "<<2*pi*r<<endl;
}

void aire_cercle()
{
    const int pi=3.14;
    float r;
    cout<<"pour calculer l'air donner moi le rayon"<<endl;
    cin>>r;
    cout<<"voici son air : "<<pi*r*r<<endl;
}

void heure()
{
    float h;
    cout<<"quelle heure est t il ?"<<endl;
    cin>>h;
    if(h>0 && h<12)
    {
        cout<<"Bonjour"<<endl;
    }
    else if (h>12 && h<18)
    {
        cout<<"bonne apres midi"<<endl;
    }
    else
    {
        cout<<"Bonsoir"<<endl;
    }
}

int main()
{
    hello_world();
    prenom();
    somme();
    moyenne();
    km_to_miles();
    surface_rectangle();
    perimetre_cercle();
    aire_cercle();
    heure();

    return 0;
}