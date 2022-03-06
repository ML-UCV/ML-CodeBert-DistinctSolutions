#include <iostream>
#include <fstream>
#include <queue>
#include <vector>


using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



struct nod

{

    int x,y,c;

    bool operator<(const nod&other)const

    {

        return c > other.c;

    }

};

priority_queue<nod> q;

vector<pair<int,int>> gr[200005],sol;



bool seen[200005];

int n,m,costmin,nr;



void citire()

{

    in>>n>>m;

    for(int i=1;i<=m;i++)

    {

        int x,y,c;

        in>>x>>y>>c;

        gr[x].push_back({y,c});

        gr[y].push_back({x,c});

    }

}

void rezolv()

{

    seen[1]=1;

    for(const auto& it:gr[1])

        q.push({1,it.first,it.second});

    while(!q.empty())

    {

        nod nd=q.top();

        int x=nd.x,y=nd.y;

        q.pop();

        if(seen[x]==1 && seen[y]==1)

            continue;

        costmin+=nd.c;

        sol.push_back({x,y});

        if(seen[x]==0)

            y=x;

        seen[y]=1;

        nr++;

        if(nr==m-1)

            break;

        for(const auto &it:gr[y])

            if(seen[it.first]==0)

                q.push({y,it.first,it.second});

    }

}

void afisare(){

    out<<costmin<<'\n'<<nr<<'\n';

    for (const auto& it: sol)

        out<<it.first<<' '<<it.second<<'\n';

}

int main()

{

    citire();

    rezolv();

    afisare();

    return 0;

}
