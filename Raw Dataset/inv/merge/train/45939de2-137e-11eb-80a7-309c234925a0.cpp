#include<fstream>
#include<iostream>
using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");



int n, v[100001];



int interclaseaza(int st, int m, int dr)

{

    int aux[dr-st+2];

    int i,j,k,nr;



    i=st;

    j=m+1;

    k=0;

    nr=0;



    while(i<=m && j<=dr)

    {



        if (v[i]<=v[j])

        {

            aux[k]=v[i++];

        }

        else

        {







            aux[k]=v[j++];

            nr=(nr+(m-i+1))%9917;

        }



        k++;

    }





    while(i<=m)

    {

        aux[k]=v[i++];

        k++;

    }





    while(j<=dr)

    {

        aux[k]=v[j++];

        k++;

    }



    for(i=st; i<=dr; i++)



        v[i]=aux[i-st];

    return nr;

}



int nrInv(int st, int dr)

{



    if (st==dr)

        return 0;



    else

    {



        int m=(st+dr)/2;



        int a=nrInv(st,m);



        int b=nrInv(m+1,dr);



        int c=a+b+interclaseaza(st,m,dr);

        return c;

    }

}

int main()

{

    int i;



    f>>n;

    for (i=0; i<n; i++)

        f>>v[i];



    g<<nrInv(0, n-1) % 9917;



    return 0;

}
