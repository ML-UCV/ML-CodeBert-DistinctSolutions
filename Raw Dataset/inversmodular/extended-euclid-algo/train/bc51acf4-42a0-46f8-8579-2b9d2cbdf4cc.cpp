#include <cstdio>


using namespace std;





void gcd(long long &x,long long &y,int a,int b)

{

    if(!b)

    {

        x=1;

        y=0;

    }

    else

    {

    gcd(x,y,b,a%b);

    long long aux=x;

    x=y;

    y=aux - y*(a/b);

    }

}



int main()

{

    long long x=0,y;



    freopen("inversmodular.in","r",stdin);

    freopen("inversmodular.out","w",stdout);



    int a,n;



    scanf("%d %d",&a,&n);



    gcd(x,y,a,n);



    if(x<=0)

        x=n+x%n;



    printf("%lld",x);



    return 0;

}
