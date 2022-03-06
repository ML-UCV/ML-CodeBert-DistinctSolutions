#include <bits/stdc++.h>




using namespace std;

ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");

char a[2000005], b[2000005];

int pi[2000005], n, m, k, sol[2000005], nr;



int main()

{

    fin.getline(a+1, 2000005);

    fin.getline(b+1, 2000005);

    a[0]='1';

    b[0]='1';

    n=strlen(a)-1;

    m=strlen(b)-1;

    for(int i=2;i<=n;i++)

    {

        while(k>0 && a[k+1]!=a[i])

            k=pi[k];

        if(a[k+1]==a[i])

            k++;

        pi[i]=k;

    }

    k=0;

    for(int i=1;i<=m;i++)

    {

        while(k>0 && a[k+1]!=b[i])

            k=pi[k];

        if(a[k+1]==b[i])

            k++;

        if(k==n)

            sol[++nr]=i-n;

    }

    fout << nr << '\n';

    for(int i=1;i<=min(nr, 1000);i++)

        fout << sol[i] << ' ';

    return 0;

}
