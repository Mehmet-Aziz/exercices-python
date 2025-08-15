#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;


void afficher_bonjour()
{
    cout<<"Bonjour"<<endl;
}


void prenom_et_age()
{
    cout<<"Quelle est ton prenom ainsi que ton age ?"<<endl;
    string prenom;
    cin>>prenom;
    cout<<endl;
    float age;
    cin>>age;
    cout<<"Ton prenom est "<<prenom<<" et tu as "<<age<<" ans"<<endl;
}

void affiche_nombre()
{
    cout<<"quelle nombre veux tu choisir et affiché ?"<<endl;
    float nombre;
    cin>>nombre;
    cout<<"tu as choisis le nombre : "<<nombre<<endl;
}

void somme()
{
    float nb1 , nb2;
    cout<<"tu veux sommer quel nombre ?"<<endl<<"entre ton premier nombre"<<endl;
    cin>>nb1;
    cout<<"entre ton deuxieme nombre"<<endl;
    cin>>nb2;
    cout<<"La somme de "<<nb1<<" + "<<nb2<<" donne : "<<nb1+nb2<<endl;
}

void aire_d_un_rectangle()
{
    float longueur , largeur;
    cout<<"pour calculer l'aire d'un rectangle , donner la longueur "<<endl;
    cin>>longueur;
    cout<<"maintenant la largeur"<<endl;
    cin>>largeur;
    cout<<"voici l'air : "<<longueur*largeur<<endl;
}

void km_to_miles()
{
    float km , miles=0.621;
    cout<<"combien de km tu veux convertir en miles ?"<<endl;
    cin>>km;
    cout<<"tu as "<<km*miles<<" miles"<<endl;
}

void perimetre_cercle()
{
    float r;
    cout<<"quelle est le rayon du cercle et je te donne son perimetre en cm"<<endl;
    cin>>r;
    cout<<"le perimetre est "<<2*3.14*r<<" cm"<<endl;
}

void positif_negatif()
{
float nb;
cout<<"donne un nombre et je te dis si il est negatif ou positif"<<endl;
cin>>nb;
if(nb>=0)
{
    cout<<nb<<" est un nombre positif"<<endl;
}
else
{
    cout<<nb<<" est un nombre negatif"<<endl;
}
}

void pair_impair()
{
    int nb;
    cout<<"choisis un nombre et je te dis si il est pair ou impair"<<endl;
    cin>>nb;
    if(nb%2==0)
    {
        cout<<nb<<" est pair"<<endl;
    }
    else
    {
        cout<<nb<<" est impair"<<endl;
    }
}

void affiche_un_a_dix()
{
    for(int i=1 ; i<11;i+=1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

void menu()
{
    int choix;
    bool fin=false;
    cout<<"bienvenu sur le menu , tu as la possibilite de faire plusieurs chose . Tape le nombre pour y avoir acces"<<endl;
    cout<<"0.quitter, 1.Bonjour, 2.prenom_age, 3.affiche_nombre, 4.somme, 5.aire_rectangle, 6.km_to_miles, 7.perimetre_cercle, 8.positif_negatif, 9.pair_impair, 10.1a10,"<<endl;
    cout<<"31. TOUT"<<endl;
    do
    {
    cin>>choix;
    switch (choix)
    {
        case 0: fin=true; break;
        case 1: afficher_bonjour(); break;
        case 2: prenom_et_age();break;
        case 3: affiche_nombre();break;
        case 4: somme();break;
        case 5: aire_d_un_rectangle();break;
        case 6:km_to_miles();break;
        case 7:perimetre_cercle();break;
        case 8:positif_negatif();break;
        case 9:pair_impair();break;
        case 10: affiche_un_a_dix();break;


        case 31:
        afficher_bonjour();
        prenom_et_age();
        affiche_nombre();
        somme();
        aire_d_un_rectangle();
        km_to_miles();
        perimetre_cercle();
        positif_negatif();
        pair_impair();
        affiche_un_a_dix();break;

        default : cout<<"erreur"<<endl;fin=true;break;
    }
    } while (fin==false);
    
}

int main()
{
    menu();
    return 0;
}