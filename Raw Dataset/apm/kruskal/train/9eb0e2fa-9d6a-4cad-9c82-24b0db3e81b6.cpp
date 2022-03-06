#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



const int DIM = 200005;



int n,m,t[DIM],rg[DIM];



long long ans=0;



struct Tuple

{

    int x,y,c;

}P[DIM];



vector <pair<int,int> > M;



bool Compare(Tuple a, Tuple b)

{

    return (a.c<b.c);

}



int Find(int nod)

{

    while(nod!=t[nod])

        nod=t[nod];

    return nod;

}



void Union(int x, int y)

{

    if(rg[x]<rg[y])

        t[x]=y;

    else if(rg[y]<rg[x])

        t[y]=x;

    else

    {

        t[x]=y;

        rg[y]++;

    }

}



void Read()

{

    fin>>n>>m;

    for(int i=1;i<=m;i++)

        fin>>P[i].x>>P[i].y>>P[i].c;

    for(int i=1;i<=n;i++)

    {

        t[i]=i;

        rg[i]=1;

    }

    sort(P+1,P+1+m,Compare);

}



void Solve()

{

    for(int i=1;i<=m;i++)

    {

        int a=P[i].x;

        int b=P[i].y;

        if(Find(a)!=Find(b))

        {

            ans+=P[i].c;

            M.push_back(make_pair(a,b));

            Union(Find(a),Find(b));

        }

    }

}



void Print()

{

    fout<<ans<<'\n';

    fout<<M.size()<<'\n';

    for(auto it : M)

        fout<<it.first<<" "<<it.second<<'\n';

}



int main()

{

    Read();

    Solve();

    Print();

}
