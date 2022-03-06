#include <bits/stdc++.h>
using namespace std;

ifstream in("strmatch.in");

ofstream out("strmatch.out");



char a[2000010],b[2000010];

const long long p1=31,p2=101,mod1=423957231,mod2=298892145;

long long stra,strb;



void citire()

{

    in>>a>>b;

    stra=strlen(a);

    strb=strlen(b);

}

void solv()

{

    long long hasha1=0,hasha2=0,hashb1=0,hashb2=0,c1=1,c2=1;

    vector<int>sol;

    for(int i=0;i<stra;i++)

    {

        hasha1=(hasha1*p1+a[i])%mod1;

        hasha2=(hasha2*p2+a[i])%mod2;

        hashb1=(hashb1*p1+b[i])%mod1;

        hashb2=(hashb2*p2+b[i])%mod2;

        c1=c1*p1%mod1;

        c2=c2*p2%mod2;

    }

    if(hasha1==hashb1 && hasha2==hashb2)

    {

        sol.push_back(0);

    }

    for(int i=stra;i<strb;i++)

    {

        hashb1=(mod1+hashb1*p1-(b[i-stra]*c1)%mod1+b[i])%mod1;

        hashb2=(mod2+hashb2*p2-(b[i-stra]*c2)%mod2+b[i])%mod2;

        if(hasha1==hashb1 && hasha2==hashb2)

        {

            sol.push_back(i-stra+1);

        }

    }

    out<<sol.size()<<'\n';

    int x=sol.size();

    for(int i=0;i<min(x,1000);i++)

    {

        out<<sol[i]<<' ';

    }

}

int main()

{

    citire();

    if(stra>strb)

    {

        out<<0;

        return 0;

    }

    solv();

    return 0;

}
