#include <iostream>
using namespace std;






float somme(float a , float b)
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
    float c;
    if(b!=0)
    {
    c=a/b;
    }
    else
    {
        return 0;
    }
    return c;
}

bool est_premier(int n)
{
    bool vrai;
    for(int i=2;i<n;i+=1)
    {
       if(n%i==0)
       {
        vrai=false;
       }
    }
    return vrai;
}

float celsius_to_fah(float c)
{
    float fah=9/5*c+32;
    return fah;
}

float max_de_trois(float a , float b , float c)
{
    if(a>b>c || a>c>b)
    {
        return a;
    }
    if(b>a>c || b>c>a)
    {
        return b;
    }
    if(c>b>a || c>a>b)
    {
        return c;
    }
}

float min_de_tab(float tab[] , int taille)
{
    float petit;
    for(int i=0;i<taille;i+=1)
    {
        for(int j=0;i<taille;i+=1)
        {
            if(i<j)
            {
                petit=i;
            }
        }
    }
    return petit;
}

float moy_de_tab(float tab[], int taille)
{
    float moy=0;
    for(int i=0;i<taille;i+=1)
    {
        moy+=tab[i];
    }
    return moy/taille;
}

void inverse(int &a , int &b)
{
    int c=a;
    a=b;
    b=c;
}

double double_valeur(int p)
{
    return 2*p;
}

void ajoute_un(int &n)
{
    n+=1;
}

double fibonacci(int n)
{
    int u0=1 , u1=1 ,u2=2 ,u_temp;
    for(int i=2;i<n;i+=1)
    {
        u_temp=u2;
        u2=u0+u1;
        u0=u1;
        u1=u_temp;
    }
    return u2;
}

float compte_voyelle(string mot)
{
    float compter=0;
    for(int i=0;i<mot.size();i+=1)
    {
        if(mot[i]=='a' || mot[i]=='A' || mot[i]=='e' || mot[i]=='E' || mot[i]=='i' || mot[i]=='I' || mot[i]=='o' || mot[i]=='O' || mot[i]=='U' || mot[i]=='u' ||mot[i]=='y' || mot[i]=='Y' )
        {
            compter+=1;
        }
    }
    return compter;
}

int main()
{
    cout<<somme(10,19)<<endl;
    cout<<soustraction(10,19)<<endl;
    cout<<multiplication(10,19)<<endl;
    cout<<division(10,19)<<endl;

    if(est_premier(10))
    {
        cout<<"il est premier"<<endl;
    }
    else
    {
        cout<<"n'est pas premier"<<endl;
    }

    cout<<celsius_to_fah(40)<<endl;
    //cout<<max_de_trois(10,19,11);
    int a=10 , b=19;
    inverse(a,b);
    cout<<b<<a<<endl;
    cout<<double_valeur(a)<<endl;
    ajoute_un(b);
    cout<<endl<<a<<b<<endl;
    cout<<fibonacci(b)<<endl;
     string mot="SALUT";
     cout<<compte_voyelle(mot)<<endl;    
    return 0;
}