#include <bits/stdc++.h>


using namespace std;

int a,n;

int euler(int x)

{

    int e=1;

    if(x%2==0)

    {

        x/=2;

        while(x%2==0)

        {

            x/=2;

            e*=2;

        }

    }

    for(int d=3;d*d<=x;d+=2)

    if(x%d==0)

    {

        x/=d;

        e*=d-1;

        while(x%d==0)

        {

            x/=d;

            e*=d;

        }

    }

    if(x>1)

        e*=x-1;

    return e;

}

int putere(int b,int e)

{

    if(e==0)

        return 1;

    int r=putere(b,e/2);

    r=1LL*r*r%n;

    if(e%2==1)

        r=1LL*r*b%n;

    return r;



}

int main()

{

    freopen("inversmodular.in","r",stdin);

    freopen("inversmodular.out","w",stdout);

    scanf("%d%d",&a,&n);

    printf("%d",putere(a,euler(n)-1));

    return 0;

}
