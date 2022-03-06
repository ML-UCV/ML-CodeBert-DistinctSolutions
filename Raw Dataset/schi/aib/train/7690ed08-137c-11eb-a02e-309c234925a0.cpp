#include <bits/stdc++.h>


using namespace std;



int n,aib[30005],cls[30005],a[30005];

ifstream f("schi.in");

ofstream g("schi.out");



void update(int p, int x)

{

    while (p<=n)

    {

        aib[p]+=x;

        p+=(p&(-p));

    }



}



int Suma(int p)

{

    int s=0;

    while (p>0)

    {

        s+=aib[p];

        p-=(p&(-p));

    }

    return s;

}



int CautBin(int p, int s)

{

    int st,dr,pos,mij;

    int suma;

    st=1;

    dr=p;

    pos=-1;

    while (st<=dr)

    {

        mij=(st+dr)/2;

        suma=Suma(mij);

        if (suma==s)

        {

            pos=mij;

            dr=mij-1;

        }

        else if (suma>s) dr=mij-1;

        else st=mij+1;

    }

    return pos;

}





int main()

{

    int pos,x,i;

    f>>n;

    for (i=1; i<=n; i++)

    {

        f>>a[i];

        update(i,1);

    }

    for (i=n; i>=1; i--)

    {

        x=a[i];

        pos=CautBin(n,x);

        update(pos,-1);

        cls[pos]=i;

    }

    for (i=1; i<=n; i++)

        g<<cls[i]<<"\n";





    return 0;

}
