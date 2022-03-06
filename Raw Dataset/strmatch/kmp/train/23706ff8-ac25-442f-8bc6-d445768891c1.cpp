#include <fstream>
#include <cstring>
#include <algorithm>




using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



char a[2000005], b[2000005];

int p[2000005];

int sol[1005], nr;

int m, n;



void formprefix(){

    p[1]=0;

    int i=0;

    for(int j=2; j<=m; j++){

        while(i>0 && a[i+1]!=a[j])

            i=p[i];

        if(a[i+1] == a[j])

            ++i;

        p[j] = i;

    }

}



void cautCuvant(){

    int k=0;

    for(int i=1; i<=n; i++){

        while(k && a[k+1]!=b[i])

            k=p[k];

        if(a[k+1] == b[i])

            ++k;

        if(k == m){

            nr++;

            if(nr<=1000)

                sol[nr] = i-m;

        }

    }



}



void afisprefix(){

    for(int i=1; i<=m; i++)

        g<<p[i]<<" ";



}



void afisSol(){

    g<<nr<<'\n';

    nr=min(nr, 1000);

    for(int i=1;i<=nr;i++)

        g<<sol[i]<<' ';

}

int main()

{

    f.getline(a+1, 2000005);

    f.getline(b+1, 2000005);

    m = strlen(a+1);

    n = strlen(b+1);

    formprefix();



    cautCuvant();

    afisSol();

    return 0;

}
