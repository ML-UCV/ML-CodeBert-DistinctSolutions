#include <iostream>
#include <fstream>
#include <cstring>




using namespace std;



ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");



char a[2000002], b[2000002];

int p[2000002], afis[2000002];

int main()

{

    int n, m, i, j, nr_afis=0;

    fin.getline(a, 2000002); n=strlen(a);

    fin.getline(b, 2000002); m=strlen(b);

    j=0; p[1]=0;

    for(i=1; i<n; i++)

    {

        while(j!=0&&a[i]!=a[j])j=p[j-1];

        if(a[i]==a[j]) j++;

        p[i]=j;

    }



    j=0;

    for(i=0; i<m; i++)

    {

        while(j!=0&&a[j]!=b[i])

        {

            j=p[j-1];

        }

        if(a[j]==b[i]) j++;

        if(j==n)

        {

            afis[++nr_afis]=i-n+1;

        }

    }

    fout<<nr_afis<<"\n";

    for(i=1; i<=min(nr_afis, 1000); i++) fout<<afis[i]<<' ';

}
