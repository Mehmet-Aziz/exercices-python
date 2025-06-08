#include <iostream>
using namespace std;

/*
voici mon projet 0
les consignes :

	Afficher un menu console avec 4 options :
 Celsius -> Fahrenheit
 Euros -> Dollars
 Quitter
	Demander à l’utilisateur de choisir une option (cin)
	Demander une valeur à convertir
	Effectuer la conversion selon le choix
	Afficher le résultat avec 2 chiffres après la virgule
	Boucler jusqu’à ce que l’utilisateur choisisse 0 (quitter)
*/


void cel_to_fah()
{

    cout<<"quelle est votre deg en Cel ?"<<endl;
    float cel;
    cin>>cel;
    //prendre n*9/5 +32
    cel=cel*9/5+32;
    cout<<"il fait "<<cel<<" deg fah"<<endl;

}

void fah_to_cel()
{

    cout<<"quelle est votre deg en fah ?"<<endl;
    float fah;
    cin>>fah;
    //prendre n*5/9 -32
    fah=fah*5/9-32;
    cout<<"il fait "<<fah<<" deg cel"<<endl;

}

void euro_to_dol()
{

    cout<<"combien d'euro vous voulez convertir en dollar ?";
    float euro;
    cin>>euro;
    //n=n*1.14
    euro=euro*1.14;
    cout<<"vous avez "<<euro<<" dollars"<<endl;
}

void dol_to_euro()
{

    cout<<"combien de dollars vous voulez convertir en euros ?";
    float dol;
    cin>>dol;
    //n=n/1.14
    dol=dol/1.14;
    cout<<"vous avez "<<dol<<" euros"<<endl;
}

int main()
{
     int choix;
    cout<<"taper 1 pour , passez de deg a fah"<<endl<<"taper 2 pour , passez de fah a deg"<<endl<<"taper 3 pour , passez de euro a dollar"<<endl<<"taper 4 pour , passez de dollar a euro"<<endl;
    cin>>choix;
    switch(choix)
    {
    case 1 :
    cel_to_fah();
    break;

    case 2 :
    fah_to_cel();
    break;

    case 3 :
    euro_to_dol();
    break;

    case 4 :
    dol_to_euro();
    break;

    default :
    cout<<"incomprehension bye";
    break;
    }

    return 0;
}