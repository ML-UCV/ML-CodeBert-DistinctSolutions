#include <bits/stdc++.h>


using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");



int x[400005], y[400005], cost[400006], ind[400005];

vector<pair<int,int>> rez;

int TT[200005];

int RG[200005];

int n, m, total;



bool cmp(int i, int j)

{

    return cost[i] < cost[j];

}



void Read()

{

    f>>n>>m;

    for(int i = 1;i <= n;++i)

    {

        RG[i] = 1;

        TT[i] = i;

    }

    for(int i = 1;i <= m;++i)

        {

            f>>x[i]>>y[i]>>cost[i];

            ind[i] = i;

        }

    sort(ind + 1, ind + m + 1, cmp);

}



int find(int x)

{

    int R, y;



    for(R = x;R != TT[R];R = TT[R]);



    while(x != TT[x])

    {

        y = TT[x];

        TT[x] = R;

        x = y;

    }

    return R;

}



void unite(int x,int y)

{

    if(RG[x] > RG[y])

        TT[y] = x;

    else

        TT[x] = y;



    if(RG[x] == RG[y]) ++RG[y];

}



void Solve()

{

    for(int i = 1;i <= m;++i)

        if(find(x[ind[i]]) != find(y[ind[i]]))

        {

            total += cost[ind[i]];

            unite(find(x[ind[i]]), find(y[ind[i]]));

            rez.push_back({x[ind[i]], y[ind[i]]});

        }

}



void Print()

{

    g<<total<<'\n';

    g<<rez.size()<<'\n';

    for(int i = 0;i < rez.size();++i)

        g<<rez[i].first<<" "<<rez[i].second<<'\n';

}



int main()

{

    Read();

    Solve();

    Print();

    return 0;

}
