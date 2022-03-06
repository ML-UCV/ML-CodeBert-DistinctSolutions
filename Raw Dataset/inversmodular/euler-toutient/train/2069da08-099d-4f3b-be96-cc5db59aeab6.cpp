#include <bits/stdc++.h>


using namespace std;

long long c,a,p,n,copie,nr,i;
long long euler(int n)

{

    p=n;copie=n;



    if(n%2==0)

    {

        p=p/2;

        while(n%2==0) n=n/2;

    }

    for(i=3; i*i<=n; i+=2)

    {

        if(n%i==0)

        {

            p=p/i;

            p*=(i-1);

            while(n%i==0) n=n/i;



        }

    }

    if(n>1)

    {

        p=p/n;

        p*=(n-1);

    }

    nr=p-1;

    p=a;

    a=1;

    while(nr)

    {

        if(nr%2==1)

        {

            a=a*p;

            a=a%copie;

        }

        p=p*p;

        p=p%copie;

        nr=nr/2;



    }



}

int main()

{

    freopen("inversmodular.in","r",stdin);

    freopen("inversmodular.out","w",stdout);

    scanf("%lld%lld",&a,&n);

    euler(n);

    printf("%lld",a%n);

    return 0;

}
