#include<cstdio>
using namespace std;

int main()

{

    freopen("cmmdc.in","r",stdin);

    freopen("cmmdc.out","w",stdout);

    int n,m;

    scanf("%d%d",&n,&m);

    while(m != 0)

    {

        int r = n % m;

        n = m;

        m = r;

    }

    if(n!=1)

    printf("%d",n);

    else

        printf("0");

    return 0;

}
