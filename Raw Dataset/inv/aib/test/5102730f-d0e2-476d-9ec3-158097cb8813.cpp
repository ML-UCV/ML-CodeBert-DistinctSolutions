#include <bits/stdc++.h>




using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");
struct sir

{

    long long val,poz;

}v[100100];





long long compare1 (sir A,sir B)

{

    if(A.val==B.val)return(A.poz<B.poz);

    return (A.val<B.val);

}





long long compare2 (sir A,sir B)

{

    return(A.poz<B.poz);

}





long long n,AIB[100100];





void adaug(long long POZ,long long x)

{

    long long i;

    for(i=POZ;i<=n;i+=(i^(i-1)&i))

        AIB[i]+=x;

}





long long suma(long long POZ)

{

    long long i,s=0;

    for(i=POZ;i>=1;i-=(i^(i-1)&i))

        s+=AIB[i];

    return s;

}





long long i,NR,k;



int main()

{

    f>>n;

    for(i=1;i<=n;i++)

    {

        f>>v[i].val;

        v[i].poz=i;

    }



    sort(v+1,v+n+1,compare1);

    for(i=1;i<=n;i++)

    {

        v[i].val=i;

    }

    sort(v+1,v+n+1,compare2);







    for(k=1;k<=n;k++)

    {

        NR+=suma(v[k].val);

        adaug(v[k].val,1);

    }





    g<<(n*(n-1)/2-NR)%9917;







    return 0;

}
