#include <cstdio>


using namespace std;

int euclid(int a, int b ,long long &x,long long &y)

{

    if(b==0)

    {

    x=1;

    y=0;

    return a;

    }

    long long x1,y1;

    int na;

    na= euclid(b,a%b,x1,y1);

    x=y1;

    y=x1-(a/b)*y1;

    return na;

}

int main()

{

    freopen("inversmodular.in","r",stdin);

    freopen("inversmodular.out","w",stdout);

    int t;

    int a,b,c;

    c=1;

    scanf("%d%d",&a,&b);

    long long x=0,y;

    int na;

    na= euclid(a,b,x,y);

    if(x<=0)

        x=b+x%b;

    printf("%lld",x);

    return 0;

}
