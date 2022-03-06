#include <fstream>
#include <cstring>


using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



int p[2000005];

char a[2000005], b[2000005];

int sol[1005];



void citire(){

    f.getline(a+1, 2000005);

    f.getline(b+1, 2000005);

}



void form_prefix(){

    int k=0;

    int m=strlen(a+1);

    p[1] = 0;

    for(int j=2; j<=m; j++){

        while(k>0 && a[k+1] != a[j])

            k = p[k];

        if(a[k+1] == a[j]){

            k++;

        }

        p[j] = k;

    }

}



int match_strings(){

    int k=0;

    int nr=0;

    int n=strlen(b+1);

    int m=strlen(a+1);

    for(int i=1; i<=n; i++){

        while(k>0 && a[k+1] != b[i])

            k = p[k];

        if(b[i] == a[k+1])

            k++;

        if(k==m){

            nr++;

            if(nr<=1000)

                sol[nr] = i-m;

            k=p[k];

        }

    }

    return nr;

}



void afisare(int nr){

    g<<nr<<'\n';

    nr = min(nr, 1000);

    for(int i=1; i<=nr; i++)

        g<<sol[i]<<' ';

}

int main()

{

    citire();

    form_prefix();

    int nr = match_strings();

    afisare(nr);

    return 0;

}
