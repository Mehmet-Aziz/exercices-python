#include <iostream>
#include <time.h>
using namespace std;

void remplir()
{
    int taille;
    cout<<"quelle est la taille de ton tableau"<<endl;
    cin>>taille;
    float tab[taille];
    for(int i=0;i<taille;i+=1)
    {
        cout<<"remplis la "<<i<<"eme case du tableau"<<endl;
        cin>>tab[i];
    }
    cout<<" on vas maintenant sommer le tableau"<<endl;
    float somme=0;
    for(int i=0;i<taille;i+=1)
    {
        somme+=tab[i];
    }
    cout<<"voici la somme : "<<somme<<endl;
    cout<<"trouvons le plus grand et plus petit nombre "<<endl;
    float grand , petit;
    for(int i =0;i<taille;i+=1)
    {
        for(int j=0;j<taille;j+=1)
        {
            if(tab[j]<tab[i])
            {
                petit=tab[j];
                grand=tab[i];
            }
        }
    }
    cout<<"la plus grande val est "<<grand<<" et la plus petite val est "<<petit<<endl;
    cout<<"faisons la moyenne du tableau"<<endl;
    float moy=0;
    for(int i=0;i<taille;i+=1)
    {
        moy+=tab[i];
    }
    moy=moy/taille;
    cout<<"la moyenne du tableau est "<<moy<<endl;
    for(int i=0;i<taille/2-1;i+=1)
    {
        float temp=tab[i];
        tab[i]=tab[taille-i];
        tab[taille-i]=temp;
    }

    for(int i=0;i<taille;i++)
    {
        if(int(tab[i])%2==0)
        {
            cout<<"la "<<i<<"eme case est pair"<<endl;
        }
         if(int(tab[i])%2==1)
        {
            cout<<"la "<<i<<"eme case est impair"<<endl;
        }
    }

    for(int i=0;i<taille;i+=1)
    {
        tab[i]=2*tab[i];
        cout<<tab[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<taille;i+=1)
    {
        tab[i]=rand()% (100+1-1)+1;
        cout<<tab[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<taille;i++)
    {
        for(int j=0;i<taille;i++)
        {
            if(tab[i]<tab[j])
            {
                float temp=tab[i];
                tab[i]=tab[j];
                tab[j]=temp;
            }
        }
    }

}

int main()
{
    remplir();
    return 0;
}