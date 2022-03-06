#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

char x[2222222],z[2222222];

int xx[2222222],zz[2222222],i,n,m,k,j,w[1111];

bool ok=false;

void pr1(){

    j=0;

    for(i=1;i<n;i++){

        while(x[i]!=x[j]&&j>0)

            j=xx[j-1];

        if(x[i]==x[j])j++;

        xx[i]=j;

    }

}

void afrez(){

    k++;

    if(k<1001)

        w[k]=i-n+1;

    j=xx[j-1];

}

void pr2(){

    j=0;

    for(i=0;i<m;i++){

        if(z[i]==x[j]&&j==n-1)

            afrez();

        while(z[i]!=x[j]&&j>0)

            j=xx[j-1];

        if(z[i]==x[j])

            j++;

    }

}

int main(){

    fin.getline(x,2222222);

    n=strlen(x);

    pr1();

    fin.getline(z,2222222);

    m=strlen(z);

    pr2();

    fout<<k<<'\n';

    for(i=1;i<=k&&i<=1000;i++)

        fout<<w[i]<<' ';

    return 0;

}
