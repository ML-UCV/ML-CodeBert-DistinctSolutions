#include <bits/stdc++.h>
using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

const int NMAX = 200005;

vector < pair<int,int> > v[NMAX],rasp;

priority_queue < pair < int , pair <int,int> > , vector < pair < int,pair <int,int> > > , greater < pair < int, pair <int,int> > > > q;

bool fixat[NMAX];

int n,m,x,y,c,cost;

int main()

{

    fin >> n >> m;

    for(int i=1;i<=m;i++){

        fin >> x >> y >> c;

        v[x].push_back({y,c});

        v[y].push_back({x,c});

    }

    q.push({0,{0,1}});

    while(!q.empty()){

        pair < int , pair <int,int> > aux=q.top();

        q.pop();

        int xx=aux.second.first,yy=aux.second.second;

        if(fixat[yy]==true) continue;

        fixat[yy]=true;

        rasp.push_back({xx,yy});

        cost+=aux.first;

        for(int i=0;i<v[yy].size();i++){

            int vecin=v[yy][i].first,cost=v[yy][i].second;

            q.push({cost,{yy,vecin}});

        }

    }

    fout << cost << '\n';

    fout << n-1 << '\n';

    for(int i=1;i<rasp.size();i++)

        fout << rasp[i].first << ' ' << rasp[i].second << '\n';

    return 0;

}
