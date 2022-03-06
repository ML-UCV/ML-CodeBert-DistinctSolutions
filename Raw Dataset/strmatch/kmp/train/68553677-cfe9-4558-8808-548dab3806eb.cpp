#include <bits/stdc++.h>


using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

int n,m,k,i,p[2000010],cnt,sol[1010];

char A[2000010],B[2000010];

int main() {

    fin>>(A+1);

    fin>>(B+1);

    n=strlen(A+1), m=strlen(B+1);

    for (i=2;i<=n;i++) {

        while (k&&A[k+1]!=A[i])

            k=p[k];

        if (A[k+1]==A[i])

            k++;

        p[i]=k;

    }

    k=0;

    for (i=1;i<=m;i++) {

        while (k&&A[k+1]!=B[i])

            k=p[k];

        if (A[k+1]==B[i])

            k++;

        if (k==n) {

            cnt++;

            if (cnt<=1000)

                sol[cnt]=i-n;

        }

    }

    fout<<cnt<<"\n";

    for (i=1;i<=min(cnt,1000);i++)

        fout<<sol[i]<<" ";

    return 0;

}
