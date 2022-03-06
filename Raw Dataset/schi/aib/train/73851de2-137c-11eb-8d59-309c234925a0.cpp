#include <bits/stdc++.h>


using namespace std;



ifstream in("schi.in");

ofstream out("schi.out");



int n,a[30001];

int tree[30001];

int sol[30001];



void adauga(int poz,int val)

{

    while(poz<=n)

    {

        tree[poz]+=val;

        poz+=poz&-poz;

    }

}



int suma(int poz)

{

    int s=0;



    while(poz)

    {

        s+=tree[poz];

        poz-=poz&-poz;

    }



    return s;

}



int main()

{

    in>>n;



    for(int i=1;i<=n;i++)

        in>>a[i];



    for(int i=1;i<=n;i++)

        adauga(i,1);



    for(int i=n;i>=1;i--)

    {

        int poz=0;



        for(int pas=n;pas;pas/=2)

            while(poz+pas<=n && suma(poz+pas)<a[i])

                poz+=pas;

        poz++;



        sol[poz]=i;

        adauga(poz,-1);

    }



    for(int i=1;i<=n;i++)

        out<<sol[i]<<'\n';



    return 0;

}
