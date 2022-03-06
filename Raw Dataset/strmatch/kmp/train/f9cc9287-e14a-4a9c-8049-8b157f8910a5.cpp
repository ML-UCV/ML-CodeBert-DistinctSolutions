#include <bits/stdc++.h>


using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



char T[2000005],P[2000005];

int a[2000005];

int urm[2000005];

int n,m,k;



void citire()

{fin>>P>>T;

 n=strlen(P);

 m=strlen(T);

}





void prefix()

{int j=0;

 for(int i=1;i<n;++i)

    {while(j>0 && P[i]!=P[j])

           j=urm[j-1];

     if(P[i]==P[j])

        j++;

     urm[i]=j;

    }

}



void kmp()

{int q=0;

 for(int i=0;i<m;++i)

    {while(q>0 && P[q]!=T[i])

           q=urm[q-1];

     if(T[i]==P[q])

        q++;

     if(q==n)

        a[k++]=i-n+1;

    }



}





int main()

{citire();

 prefix();

 kmp();

 fout<<k<<"\n";

 if(k>1000) k=1000;

 for(int i=0;i<k;++i)

     fout<<a[i]<<" ";





    return 0;

}
