#include <fstream>
#include <iostream>
using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int a[120001],v[30001],sol[30001];

int n,i,j,poz;



void build(int nod, int st, int dr){

    if(st==dr){

        a[nod]=1;

        return;

    }



    int mid=(st+dr)/2;

    build(2*nod,st,mid);

    build(2*nod+1,mid+1,dr);

    a[nod]=a[2*nod]+a[2*nod+1];

}



void update(int nod, int st, int dr, int p){

    if(st==dr){

        a[nod]--;

        return;

    }



    int mid=(st+dr)/2;



    if(p<=mid) update(2*nod,st,mid,p);

    else update(2*nod+1,mid+1,dr,p);

    a[nod]=a[2*nod]+a[2*nod+1];

}



int query(int nod, int st, int dr, int x){

    if(st==dr)

        return st;



    int mid=(st+dr)/2;



    if(a[2*nod]>=x)

        return query(2*nod,st,mid,x);

    else

        return query(2*nod+1,mid+1,dr,x-a[2*nod]);

}



int main(){

    fin>>n;

    build(1,1,n);
    for(i=1;i<=n;i++)

        fin>>v[i];



    for(i=n;i;i--){

        poz=query(1,1,n,v[i]);

        update(1,1,n,poz);

        sol[poz]=i;



    }



    for(i=1;i<=n;i++)

        fout<<sol[i]<<"\n";



    return 0;

}
