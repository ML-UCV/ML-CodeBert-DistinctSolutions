#include <fstream>


using namespace std;

ifstream cin("inversmodular.in");

ofstream cout("inversmodular.out");

int n,ct;

int fi(int n)

{

    int d=2;

    long long ans=n;

    while(n>1 and d*d<=n)

    {

        int p=0;

        while(n%d==0)

            n/=d, p=1;

        if(p)

            ans=1LL*ans/d*(d-1)%ct;

        d++;

    }

    if(n!=1)

        ans=1LL*ans*(n-1)/n;

    return ans;

}

long long put(int a, int b)

{

    a%=ct;

    if(b==0)

        return 1;

    if(b%2)

        return 1LL*a*put(a,b-1)%ct;

    long long p=put(a,b/2);

    return 1LL*p*p%ct;

}

int main()

{

    int a;

    cin>>a>>n;

    ct=n;

    cout<<1LL*put(a,fi(n)-1)%ct;

}
