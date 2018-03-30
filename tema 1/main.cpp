#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
/*
    numar_stari numar_litere
    alfabet
    stare_initiala
    numar_stari_finale
    stari_finale
    numar_tranzitii
    tranzitii
*/
ifstream f("date.in");

int i,j;
int nr_stari,nr_litere;
string alfabet[100];
int mat[100][100];

int verificare(string cuv, int x)
{
    for (int i = 0; i < nr_litere; i++)
        if (cuv.find(alfabet[i])==0)
            return(mat[x][i]);

    return-1;
}
int main()
{
    f>>nr_stari;
    f>>nr_litere;

    for (i=0; i<nr_litere; i++)
        f>>alfabet[i];

    int stare[nr_stari];

    for(i=0; i<nr_stari; i++)
        stare[i]=0;

    int stare_initiala;

    f>>stare_initiala;
    stare[stare_initiala]=1;

    int nr_stari_finale;
    f>>nr_stari_finale;

    for (i=0; i<nr_stari_finale; i++)
    {
        int stare_finala;
        f>>stare_finala;
        stare[stare_finala]=2;
    }

    int nr_tranzitii;
    f>>nr_tranzitii;

    for (i=0; i<nr_stari; i++)
        for(j=0; j<nr_litere; j++)
            mat[i][j]=-1;
    for( i=0; i<nr_tranzitii; i++)
    {
        int p,u;
        string l;
        f>>p>>l>>u;
        j=0;
        while(l!=alfabet[j]&&j<=nr_litere)
            j++;
        mat[p][j]=u;
    }

    string cuvant;


    int ok,b;
    ok=0;
    b=stare_initiala;
    string nume;
    int nr;
    cout<<"Nr. cuvinte:";
    cin>>nr;
    cout<<"Cuvant:";
    while (nr!=0)
    {
        cin>>cuvant;
        if(cuvant=="0")
        {
            if(stare[stare_initiala]==2)
            {
                cout<<"Cuvantul vid este acceptat!";
                return 0;
            }
            else
            {
                cout<<"Cuvantul vid nu este acceptat!";
                return 0;
            }
        }
        b = verificare(cuvant, b);
        nr--;
        if (b < 0)
            break;

    }
    if (stare[b]==2)
        ok=1;

    if (ok==1)
        cout<<"Cuvantul este acceptat de automat!";
    else
        cout<<"Cuavntul nu este acceptat de automat!";
    return 0;
}
