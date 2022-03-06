#include <bits/stdc++.h>


using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

int n,i,j,aib[30009],v[30009],poz[30009];

void add(int x,int val)

{

    for(int i=x;i<=n;i+=i&(-i))

            aib[i]+=val;

}

int sum (int x )

{

    int s=0;

    for(int i=x;i>=1;i-=i&(-i))

        s+=aib[i];

    return s;

}

int bin(int st,int dr,int val)

{

    int mij;

    int minim=INT_MAX;

    while(st<=dr)

    {

        mij=(st+dr)/2;

        int S=sum(mij);

        if(S==val&&minim>mij)

            minim=mij;

        else

            if(S>=val)

                dr=mij-1;

            else

                st=mij+1;

    }

    return minim;

}

int main()

{

    fin.sync_with_stdio(false);

    fin>>n;

    for(i=1;i<=n;i++)

        fin>>v[i];

    for(i=1;i<=n;i++)

        aib[i]=i&(-i);

    for(i=n;i>=1;i--)

    {

        int ans=bin(1,n,v[i]);

        add(ans,-1);

        poz[ans]=i;

    }

    for(i=1;i<=n;i++)

        fout<<poz[i]<<'\n';

    return 0;

}
