#include <bits/stdc++.h>


using namespace std;



struct edge

{

    int e1, e2, cost;

};



ifstream f("apm.in");

ofstream g("apm.out");

int n, m, x, y, cost, total;

int TT[200005];

int RG[200005];

vector<edge> edges;

vector<pair<int, int>> rez;



int find(int x)

{

    int R, y;



    for(R = x;R != TT[R]; R = TT[R]);



    while(x != TT[x])

    {

        y = TT[x];

        TT[x] = R;

        x = y;

    }



    return R;

}



void unite(int x, int y)

{

    if(RG[x] > RG[y])

        TT[y] = x;

    else

        TT[x] = y;



    if(RG[x] == RG[y]) ++RG[y];



}



void Read()

{

    f>>n>>m;

    for(int i = 1;i <= m;++i)

    {

        f>>x>>y>>cost;

        edges.push_back({x, y, cost});

    }

}



bool cmp(edge m1, edge m2)

{

    return m1.cost < m2.cost;

}



void Solve()

{

    for(int i = 1;i <= n;++i)

    {

        TT[i] = i;

        RG[i] = 1;

    }

    sort(edges.begin(), edges.end(), cmp);

    for(vector<edge>::iterator it = edges.begin();it != edges.end();++it)

            if(find((*it).e1) != find((*it).e2))

            {

                total += (*it).cost;

                unite(find((*it).e1), find((*it).e2));

                rez.push_back(make_pair((*it).e1, (*it).e2));

            }

}



void Print()

{

    g<<total<<'\n';

    g<<rez.size()<<'\n';

    for(vector<pair<int, int>>::iterator it = rez.begin();it != rez.end();++it)

        g<<(*it).first<<" "<<(*it).second<<'\n';

}



int main()

{

    Read();

    Solve();

    Print();

    return 0;

}
