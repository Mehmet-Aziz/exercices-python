#include <iostream>
using namespace std;

/*

projet1:

Objectif:
Créer un petit programme console qui fait des calculs simples (+, -, *, /) 
entre deux nombres, avec un menu pour choisir l’opération.
*/

/*
consigne faites par chatgpt , pas vraiment de libre arbitre pour m'entrainer

Étape 1 : Afficher un menu

    Affiche un menu avec ces options :

        Addition

        Soustraction

        Multiplication

        Division

        Quitter

    Demande à l’utilisateur de choisir une option.

Étape 2 : Demander les nombres

    Si l’option choisie est entre 1 et 4, demande deux nombres (float ou double).

Étape 3 : Effectuer le calcul et afficher le résultat

    Selon l’option, fais le calcul correspondant et affiche le résultat.

    Pour la division, gère le cas où le diviseur est zéro (affiche un message d’erreur).

Étape 4 : Boucler le menu

    Tant que l’utilisateur ne choisit pas 0, le menu revient.
*/

void menu()
{
    cout<<"Bienvenue dans le Menu Calculatrice"<<endl<<"Voici les differents types d'oppeérations possible"<<endl;
    cout<<"1. Addition - 2.Soustraction - 3.Multiplication - 4.Division - 5.Quitter"<<endl;
}

void opperations(float &a ,int &choix, float &b)
{
    cout<<"choissis ton premier nombre"<<endl;
    cin>>a;
    cout<<"choissis l'opperation "<<endl;
    cin>>choix;
    cout<<"choissis le deuxieme nombre"<<endl;
    cin>>b;
}

float addition(float a , float b)
{
    return a+b;
}

float soustraction(float a , float b)
{
    return a-b;
}

float multiplication(float a , float b)
{
    return a*b;
}

float division(float a , float b)
{
    if(b==0)
    {
        cout<<"Operation pas possible"<<endl;
        return 404;
    }
    else
    {
        return a/b;
    }
}



int main()
{
    int choix;
    float a,b;
    do
    {
        menu();
    
        opperations(a,choix,b);
        switch(choix)
    {
        case 1 :
        cout<<addition(a,b);
        break;

        case 2 :
        cout<<soustraction(a,b);
        break;

        case 3 :
        cout<<multiplication(a,b);
        break;

        case 4 :
        cout<<division(a,b);
        break;

        case 5 :
        cout<<"Merci encore d'avoir utilisé Calcultarice"<<endl;
        break;

        default :
        cout<<"incomprehension , choisissez de nouveaux"<<endl;
        cin>>choix;
        break;
    }
    }
    while(choix<1 || choix>6);
     return 0;
}