#include <bits/stdc++.h>




using namespace std;





ifstream f("inv.in");

ofstream g("inv.out");







struct normalizare

{

    int val,poz;

}v[100100];





int compare (normalizare A,normalizare B)

{

    if(A.val == B.val)return (A.poz<B.poz);

    return (A.val<B.val);

}



int n,AIB[100100];





void adaug(int poz,int val)

{

    int i;

    for(i=poz;i<=n;i+=(i&(-i)))

        AIB[i]+=val;

}



int suma(int poz)

{

    int i,S=0;

    for(i=poz;i>=1;i-=(i&(-i)))

        S+=AIB[i];

    return S;

}



int i,x,total,numere_mai_mari,sol[100100];



int main()

{

    f>>n;

    for(i=1;i<=n;i++)

    {

        f>>x;

        v[i].val=x;

        v[i].poz=i;

    }



    sort(v+1,v+n+1,compare);



    for(i=1;i<=n;i++)

    {

        sol[v[i].poz]=i;

    }





    for(i=1;i<=n;i++)

    {

        x=sol[i];



        numere_mai_mari=suma(n)-suma(x);

        total = (total+numere_mai_mari) % 9917;



        adaug(x,1);



    }



    g<<total%9917;



    return 0;

}
