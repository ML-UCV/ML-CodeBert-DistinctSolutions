#include <bits/stdc++.h>
using namespace std;

int cmmdc(int a,int b)

{

    int r;

    while(b)

    {

        r=a%b;

        a=b;

        b=r;

    }

    return a;

}

int main()

{
    freopen("cmmdc.in","r",stdin);

    freopen("cmmdc.out","w",stdout);



    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    int a,b;

    cin>>a>>b;

    if(cmmdc(a,b)!=1)

        cout<<cmmdc(a,b);

    else

        cout<<0;

    return 0;

}
