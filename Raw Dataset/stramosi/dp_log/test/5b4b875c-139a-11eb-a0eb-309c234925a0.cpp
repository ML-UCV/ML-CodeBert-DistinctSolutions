#include <bits/stdc++.h>


using namespace std;

ifstream in("stramosi.in");

ofstream out("stramosi.out");

int n,m,t[250100],p,q,x,sum;

int s[20][250100];

int lg(int x)

{

    int ans=0;

    while(x/2>=1)

    {

        x/=2;

        ans++;

    }

    return ans;

}

int find(int x,int t)

{

    int p=x;

    int sum=0;

    int nr=lg(t);

    while(sum<t)

    {

        if(sum+(1<<nr)>t) nr--;

        else

        {

            p=s[nr][p];

            sum+=(1<<nr);

        }

    }

    return p;

}

int main()

{

    in>>n>>m;

    for(int i=1;i<=n;i++)

    {

        in>>x;

        t[i]=x;

    }

    for(int i=1;i<=n;i++) s[0][i]=t[i];

    for(int i=1;i<20;i++)

        for(int j=1;j<=n;j++)

            s[i][j]=s[i-1][s[i-1][j]];

    while(m--)

    {

        in>>q>>p;

        out<<find(q,p)<<'\n';

    }

    return 0;

}
