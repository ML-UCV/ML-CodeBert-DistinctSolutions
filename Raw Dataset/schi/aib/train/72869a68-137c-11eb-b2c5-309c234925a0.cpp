#include <bits/stdc++.h>


using namespace std;

int aib[30005],v[30005],sol[30005],n;

int len(int x){

    return x-(x&(x-1));

};



void update(int poz,int val){

    while(poz<=n){

        aib[poz]+=val;

        poz+=len(poz);

    }

};



int main()

{

    ifstream cin("schi.in");

    ofstream cout("schi.out");

    int i,x,poz,rez;

    cin>>n;

    for(i=1;i<=n;i++){

        cin>>v[i];

        update(i,1);

    }

    for(i=n;i>=1;i--){

        x=v[i];

        rez=0;

        poz=1<<20;

        while(poz>0){

            if(rez+poz<=n && aib[rez+poz]<x){

                rez+=poz;

                x-=aib[rez];

            }

            poz/=2;

        }

        rez++;

        sol[rez]=i;

        update(rez,-1);

    }

    for(i=1;i<=n;i++)

        cout<<sol[i]<<'\n';

    return 0;

}
