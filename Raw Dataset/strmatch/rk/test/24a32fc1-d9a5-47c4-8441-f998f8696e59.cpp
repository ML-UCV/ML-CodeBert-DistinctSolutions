#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream f ("strmatch.in");

ofstream g ("strmatch.out");







char s1[2000009],s2[2000009];

int p1=1,p2=1;

int ans[1009],k,n,m;

int HASH1,HASH2 ,Hash1,Hash2;

int main(){

    f>>s1>>s2;

    n=strlen(s1);

    m=strlen(s2);

    for(int i=0;i<n;i++){

        HASH1=(HASH1*73 +s1[i])%100007;

        HASH2=(HASH2*73 +s1[i])%100021;

        if(i!=0)

            p1=(p1*73)%100007,p2=(p2*73)%100021;

    }

    for(int i=0;i<n;i++){



        Hash1=(Hash1*73 +s2[i])%100007;



        Hash2=(Hash2*73 +s2[i])%100021;

    }

    if(HASH1==Hash1&&HASH2==Hash2)

        ans[++k]=0;

    for(int i=n;i<m;i++){

        Hash1=((Hash1-(s2[i-n]*p1)%100007 +100007)*73 +s2[i])%100007;

        Hash2=((Hash2-(s2[i-n]*p2)%100021 +100021)*73 +s2[i])%100021;

        if(HASH1==Hash1&&HASH2==Hash2){

            k++;

            if(k<=1000)

                ans[k]=i-n+1;

        }

    }

        g<<k<<"\n";

    for(int i=1;i<=min(1000,k);i++)

        g<<ans[i]<<' ';

}
