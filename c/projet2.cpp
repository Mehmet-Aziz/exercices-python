#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/*
projet2

consignes :
🧩 FONCTIONNALITÉS à coder :

    Ajouter un nouvel élève (nom)

    Ajouter une note à un élève existant

    Afficher les notes d’un élève

    Afficher la moyenne de chaque élève

    Quitter

➡️ Menu avec while, switch ou if
*/

struct eleve
{
char nom[50];
vector<float> notes;
};


void affichage(eleve &e)
{
cout<<"voici le nom :"<<e.nom<<endl;
cout<<"voici les notes :";
for(int i=0;i<e.notes.size();i+=1)
{
    cout<<e.notes[i]<<" ";
}
cout<<endl<<"voici la moyenne :";
float moy=0.0;
for(int i=0;i<e.notes.size();i+=1)
{
moy+=e.notes[i];
}
moy=moy/e.notes.size();
cout<<moy<<endl;
}


int main()
{
    vector<eleve> classe;
    int continuer1=1;

    do
    {
        eleve temp;
        cout<<"Quel est son nom ?"<<endl;
        cin>>temp.nom;
        int continuer2=0;
        do
        {
            float note;
            cout<<"quelle est sa note ?"<<endl;
            cin>>note;
            temp.notes.push_back(note);
            cout<<"c'est finis ? tape 0 pour non sinon tape 1"<<endl;
            cin>>continuer2;
        } while (continuer2==0);

        classe.push_back(temp);

        cout<<endl<<"on ajoute nouvel eleve ? 0 pour non , 1 pour oui"<<endl;
        cin>>continuer1;
        
    } while (continuer1==1);
    
    cout<<"voici la liste de tout les eleves :"<<endl;
    for(int i=0;i<classe.size();i+=1)
    {
        affichage(classe[i]);
    }

    return 0;
}