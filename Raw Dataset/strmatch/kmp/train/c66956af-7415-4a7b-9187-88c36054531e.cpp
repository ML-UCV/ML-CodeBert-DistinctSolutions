#include <bits/stdc++.h>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

int n,m,l,i,cnt,sol[1010],p[2000010];

char a[2000010],b[2000010];

int main() {

    fin>>a+1>>b+1;

    n=strlen(a+1);

    m=strlen(b+1);



    for(i=2;i<=n;i++){

        while(l && a[l+1]!=a[i])

            l=p[l];



        if(a[i]==a[l+1])

            l++;



        p[i]=l;

    }

    l=0;



    for(i=1;i<=m;i++){

        while(l && a[l+1]!=b[i])

            l=p[l];



        if(b[i]==a[l+1])

            l++;



        if(l==n){

            if(++cnt<=1000)

                sol[cnt]=i-l;

            l=p[l];

        }

    }



    fout<<cnt<<"\n";

    for(i=1;i<=min(1000,cnt);i++)

        fout<<sol[i]<<" ";



    return 0;

}
