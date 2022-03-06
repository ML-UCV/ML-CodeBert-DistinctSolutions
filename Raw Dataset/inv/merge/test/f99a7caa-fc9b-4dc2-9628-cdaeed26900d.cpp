#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");



int n, a[100001], b[100001];



void Read()

{

    fin >> n;

    for(int i=1; i<=n; i++)

        fin >> a[i];

}



long long Inv(int st, int dr)

{

    int mij;

    mij=(st+dr)/2;

    if(st==dr)

        return 0;

    long long inv1, inv2;

    inv1=Inv(st,mij)%9917;

    inv2=Inv(mij+1,dr)%9917;

    int i=st;

    int j=mij+1;

    int k=st-1;

    long long inv3=0;

    while(i<=mij && j<=dr)

        if(a[j]<a[i])

          b[++k]=a[j++];

        else

        {

            b[++k]=a[i++];

            inv3+=j-mij-1;

        }

    while(i<=mij)

    {

        b[++k]=a[i++];

        inv3+=dr-mij;

    }

    while(j<=dr)

        b[++k]=a[j++];



    for(i=st; i<=dr; i++)

        a[i]=b[i];



    return (inv1+inv2+inv3)%9917;

}



int main()

{

    Read();

    fout << Inv(1,n);



    return 0;

}
