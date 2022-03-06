#include <bits/stdc++.h>


using namespace std;



int n;



int rid_put(int a,int b)

{

    int sol=1;

    for(long long i=1;i<=b;i<<=1)

    {

        if(b&i) sol=(1LL*sol*a)%n;

        a=(1LL*a*a)%n;

    }

    return sol;

}



int main()

{

    freopen("inversmodular.in","r",stdin);

    freopen("inversmodular.out","w",stdout);

    int a;

    scanf("%d%d",&a,&n);

    int fi=n,nr=n;

    for(int i=2;i*i<=nr;i++)

        if(nr%i==0)

        {

            while(nr%i==0) nr/=i;

            fi=(fi/i)*(i-1);

        }

    if(nr>1) fi=(fi/nr)*(nr-1);

    printf("%d",rid_put(a,fi-1));

    return 0;

}
