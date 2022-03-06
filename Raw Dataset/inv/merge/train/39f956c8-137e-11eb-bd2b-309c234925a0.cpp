#include <bits/stdc++.h>


using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");

int rasp=0,a[200005],aux[200005],sol=0,mod=9917,n;

void interclaseaza(int pozst,int mij,int dr)

{

    int i=pozst;

    int j=mij+1;

    int nr=0,cnt=0,rasp=0;



    while(i<=mij&&j<=dr)

    {

        if(a[i]>a[j])

        {

            nr++;

            aux[++cnt]=a[j];

            j++;



        }

        else

        {

            rasp+=nr;

            aux[++cnt]=a[i];

            i++;

        }

    }

    while(i<=mij)

    {

        rasp+=nr;

        aux[++cnt]=a[i];

        i++;

    }

    while(j<=dr)

    {

        aux[++cnt]=a[j];

        j++;

    }

    sol=(sol+rasp)%mod;

    for(int i=pozst;i<=dr;i++)

    {

        a[i]=aux[i-pozst+1];

    }

}

void mergesort(int st,int dr)

{

    if(st<dr){

    int mij=(st+dr)/2;

    mergesort(st,mij);

    mergesort(mij+1,dr);

    interclaseaza(st,mij,dr);

    }



}

int main()

{

f>>n;

for(int i=1;i<=n;i++)

{

    f>>a[i];

}

mergesort(1,n);

g<<sol;

}
