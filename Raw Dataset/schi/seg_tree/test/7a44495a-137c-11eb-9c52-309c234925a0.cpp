#include <iostream>
#include <fstream>




using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");



int n,i,j,nr,k;

int v[30005],ct[4*30005],rz[30005];



void build(int n,int l,int r)

{

    if(l==r)

    {

        ct[n]=1;

        return;

    }

    int m=(l+r)/2;

    build(2*n, l, m);

    build(2*n+1,m+1,r);



    ct[n]=ct[2*n]+ct[2*n+1];

}



void update(int n,int l,int r,int val)

{

    if(l==r)

    {

        rz[l]=i;

        ct[n]=0;

        return;

    }

    int m=(l+r)/2;

    if(ct[2*n]>=val) update(2*n,l,m,val);

    else update(2*n+1,m+1,r,val-ct[2*n]);



    ct[n]=ct[2*n]+ct[2*n+1];

}



int main()

{

    fin>>n;

    for(i=1;i<=n;i++)

        fin>>v[i];



    build(1,1,n);



    for(i=n;i>=1;i--)

        update(1,1,n,v[i]);



    for(i=1;i<=n;i++)

        fout<<rz[i]<<"\n";

}
