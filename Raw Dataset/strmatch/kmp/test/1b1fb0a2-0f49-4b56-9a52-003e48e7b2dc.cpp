#include <fstream>
#include <cstring>
#include <vector>
using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int NMAX=2000010;

char a[NMAX],b[NMAX];

int n,m;

int prefix[NMAX];

vector<int>sol;

int nr;

void citire()

{

    fin.getline(a+1,NMAX);

    fin.getline(b+1,NMAX);

    n=strlen(a+1);

    m=strlen(b+1);

}

void calcularePrefix()

{

    int j=0;

    for (int i=2; i<=n; i++){

        while (j>0 && a[j+1]!=a[i]){

            j=prefix[j];

        }

        if (a[j+1]==a[i]){

            j++;

        }

        prefix[i]=j;

    }

}

void kmp()

{

    calcularePrefix();

    int j=0;

    for (int i=1; i<=m; i++){

        while (j>0 && a[j+1]!=b[i]){

            j=prefix[j];

        }

        if (a[j+1]==b[i]){

            j++;

        }

        if (j==n){

            sol.push_back(i-n);

            j=prefix[j];

        }

    }

}

void afisare()

{

    int nr=sol.size();

    fout<<nr<<'\n';

    if (nr>1000)

        nr=1000;

    for (int i=0; i<nr; i++)

        fout<<sol[i]<<' ';

    fout<<'\n';

}

int main()

{

    citire();

    kmp();

    afisare();

    return 0;

}
