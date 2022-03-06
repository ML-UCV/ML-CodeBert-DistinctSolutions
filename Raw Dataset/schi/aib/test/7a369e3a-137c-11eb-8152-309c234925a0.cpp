#include <bits/stdc++.h>




using namespace std;



ifstream f("schi.in");

ofstream g("schi.out");



int AIB[30100],n;



void adaug(int poz,int val)

{

    int i;

    for(i=poz;i<=n;i+=(i&(-i)))

        AIB[i]+=val;

}



int nr_de0(int poz)

{

    int i,nr0=0;

    for(i=poz;i>=1;i-=(i&(-i)))

        nr0+=AIB[i];

    return nr0;

}





int i,x,p,u,mij,cp,pozitie,v[30100],sol[30100];



int main()

{

    f>>n;

    for(i=1;i<=n;i++)

    {

        f>>v[i];

        adaug(i,1);

    }



    for(i=n;i>=1;i--)

    {

        p=1;u=n;x=v[i];cp=0;



        while(p<=u)

        {

            mij=(p+u)/2;

            if(nr_de0(mij)>=x){cp=mij;u=mij-1;}

            else {p=mij+1;}

        }

        sol[cp]=i;

        adaug(cp,-1);

    }



    for(i=1;i<=n;i++)

        g<<sol[i]<<'\n';



    return 0;

}
