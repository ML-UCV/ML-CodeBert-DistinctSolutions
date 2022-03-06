#include <fstream>
#include <string.h>
#include <vector>




using namespace std;



int la,lb,i,j,rez;

char a[2000005],b[2000005];

vector<int> urm;

vector<int> poz;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



void citire(){

    fin>>a>>b;

    la=strlen(a);

    lb=strlen(b);

    urm.assign (la+5,0);

    poz.assign (1005,0);

}



void prefix(){

    int k=0;

    for (i=1; i<la; i++){

        while (k>0 && a[k]!=a[i]) k=urm[k-1];

        if (a[k]==a[i]) k++;

        urm[i]=k;

    }

};



void rezolvare(){

    prefix();

    j=0;

    for (i=0;i<lb; i++){

        while (j>0 && a[j]!=b[i]) j=urm[j-1];

        if (a[j]==b[i]) j++;

        if (j==la){

            if (rez<1000) poz[++rez]=i-la+1;

            else rez++;

            j=urm[j-1];

        }

    }

}



void scriere(){

    fout<<rez<<'\n';

    if (rez>1000) rez=1000;

    for (i=1;i<=rez;i++)

        fout<<poz[i]<<" ";

}



int main()

{

    ios_base::sync_with_stdio(false);;

    fin.tie(0);

    fout.tie(0);

    citire();

    prefix();

    rezolvare();

    scriere();

    return 0;

}
