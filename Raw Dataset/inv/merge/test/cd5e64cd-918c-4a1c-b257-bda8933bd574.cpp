#include <iostream>
#include <fstream>
using namespace std;



int v[100001];

int mergeSort(int l,int r)

{

    int i,j,k,mij,counter,t[100001];

    mij=(l+r)/2;

    i=l;

    j=mij+1;

    k=0;

    counter=0;

    while(i<=mij && j<=r)

    {

        if(v[i]<=v[j])

        {

            t[k]=v[i++];

        }

        else

        {

            t[k]=v[j++];

            counter+=mij-i+1;

            counter%=9917;

        }

        k++;

    }

    while(i<=mij)

    {

        t[k]=v[i++];

        k++;

    }

    while(j<=r)

    {

        t[k]=v[j++];

        k++;

    }

    for(i=l;i<=r;i++)

    {

        v[i]=t[i-l];

    }

    return counter;

}

int inversiuni(int st, int dr)

{

    if (st>=dr)

    {

        return 0;

    }

    int mij,x,y,z;

    mij=(st+dr)/2;

    x=inversiuni(st,mij);

    y=inversiuni(mij+1,dr);

    z=x+y+mergeSort(st,dr);

    return z;

}

int main()

{

    ifstream fin("inv.in");

    ofstream fout("inv.out");

    int n,i,counter=0;

    fin>>n;

    for(i=1;i<=n;i++)

    {

        fin>>v[i];

    }

    fout<<inversiuni(1,n)%9917;

    fin.close();

    fout.close();

    return 0;

}
