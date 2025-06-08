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

int main()
{
    do
    {
        bool vrai=false;
        vector<eleve> e;
        cout<<"quelle est le nom de l'eleve ?"<<endl;
        cin>>e.nom;
        do
        {
            bool fini=false;
            int i=0;
            cout<<"quelle est sa note ?"<<endl;
            cin>>e.notes[i];
            i+=1;
            cout<<"si c'est finis tape 0, sinon tape 1"<<endl;
            cin>>fini;

        }
        while(finis!=false);

        cout<<endl<<"description de l'eleve"<<endl;
        cout<<"Prenom :"<<e.nom<<endl;
        cout<<"notes :"<<endl:
        for(int i=0;i<e.notes.size(),i+=1)
        {
            cout<<e.notes[i]<<endl;
        }
        cout<<"Moyenne :"<<endl;
        float moy=0;
        for(int i=0;i<e.notes.size();i+=1)
        {
        moy+=e.notes[i];
        }
        moy=moy/e.notes.size();
        cout<<moy;
        cout<<endl<<"on continue sur un nouvelle eleve ?, 1 pour oui , sinon 0"<<endl;
        cin>>vrai;
    } while (vrai==0);
    
    return 0;
}