#include <bits/stdc++.h>


using namespace std;



ifstream f("schi.in");

ofstream g("schi.out");

int n,i,z,a[120010],b[30010],ans[30010];

int fnd(int val,int poz)

{

    if(poz>z)return poz-z;

    if(a[poz*2]>=val)

        return fnd(val,poz*2);

    else

        return fnd(val-a[poz*2],poz*2+1);

}

void upd(int poz)

{

    poz+=z;

    while(poz)

    {

        a[poz]--;

        poz>>=1;

    }

    return ;

}

int main()

{

    f>>n;

    z=1;while(z<n)z<<=1;z--;

    for(i=1;i<=n;i++)

        a[z+i]=1;

    for(i=z;i>=1;i--)

        a[i]=a[i*2]+a[i*2+1];

    for(i=1;i<=n;i++)

        f>>b[i];

    for(i=n;i>=1;i--)

    {

        int y=fnd(b[i],1);

        upd(y);

        ans[y]=i;

    }

    for(i=1;i<=n;i++)

        g<<ans[i]<<'\n';

    return 0;

}
