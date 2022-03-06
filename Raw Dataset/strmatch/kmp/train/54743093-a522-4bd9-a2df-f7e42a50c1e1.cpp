#include <fstream>
#include <cstring>
using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

int lps[2000010],v[1010],n,m;

char A[2000010],B[2000010];

void BuildLPS()

{

    int i,k=0;

    lps[1]=0;

    for (i=2;i<=n;i++)

    {

        while (k>0 && B[i-1]!=B[k]) k=lps[k];

        if (B[i-1]==B[k]) k++;

        lps[i]=k;

    }

}

void KMP()

{

    int k=0,q=0,i;

    for (i=0;i<m;i++)

    {

        while (q>0 && A[i]!=B[q]) q=lps[q];

        if (B[q]==A[i]) q++;

        if (q==n) {

                k++;

                if (k<=1000) v[k]=i-n+1;

        }

    }

        g<<k<<'\n';

        if (k>=1000) k=1000;

    for (i=1;i<=k;i++) g<<v[i]<<" ";

}

int main()

{

    f.getline(B,2000005);

    f.getline(A,2000005);

    n=strlen(B);

    m=strlen(A);

    BuildLPS();

    KMP();

    return 0;

}
