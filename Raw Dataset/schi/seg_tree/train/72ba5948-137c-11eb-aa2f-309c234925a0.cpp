#include <bits/stdc++.h>


using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

int a[30004],v[4*30004],sum,n,i,sol[30004];

void build(int nod,int st,int dr){

    if(st==dr){

        v[nod]=1;

        return;

    }

    int mid=(st+dr)/2;

    build(nod*2,st,mid);

    build(nod*2+1,mid+1,dr);

    v[nod]=v[nod*2]+v[nod*2+1];

}

int query(int nod,int st,int dr){



    if(st==dr){

        v[nod]=0;

        return st;

    }

    int mid=(st+dr)/2;

    v[nod]--;

    if(v[2*nod]>=sum)

         return query(2*nod,st,mid);

        sum-=v[2*nod];

          return query(2*nod+1,mid+1,dr);

}

int main()

{

    fin>>n;

    for(i=1;i<=n;i++)

        fin>>a[i];

 build(1,1,n);

 for(i=n;i>=1;i--){

    sum=a[i];

   int poz= query(1,1,n);

   sol[poz]=i;

 }

 for(i=1;i<=n;i++)

    fout<<sol[i]<<'\n';

}
