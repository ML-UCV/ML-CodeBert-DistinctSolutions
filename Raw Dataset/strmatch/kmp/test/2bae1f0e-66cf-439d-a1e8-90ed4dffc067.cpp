#include <bits/stdc++.h>

using namespace std;

ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

void Citire();
void Pref();
void KMP();


string T,P;
int k;
int a[2000005],lps[2000005];

int main(){
    fin>>P>>T;

    KMP();

    fout<<k<<"\n";
    if(k>1000) k=1000;
    for(int i=1;i<=k;++i)
        fout<<a[i]<<' ';
}

void Pref(){

    int j=0;

    for(int i=1;i<P.size();++i){
        int i2=i;
        for(;i<2000005 and P[i]==P[i-i2]; ++i)
            lps[i]=i-i2+1;
        if(i2!=i) --i;
    }
}


void KMP()
{
    Pref();
    int q=0;
    for(int i=0;i<T.size();++i){

        while(q>0 && P[q]!=T[i]) q=lps[q-1];

        if(P[q]==T[i]) ++q;
        if(q==P.size()) a[++k]=i-P.size()+1;
    }



}
