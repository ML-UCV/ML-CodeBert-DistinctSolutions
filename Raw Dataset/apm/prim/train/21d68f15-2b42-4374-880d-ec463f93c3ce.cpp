#include <iostream>
#include <fstream>
#include <queue>
#include <vector>


const int MAXN = 200000 + 5;



using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



typedef pair<int,pair<int,int> > pii;



vector<pair<int,int> >graf[MAXN];

priority_queue<pii,vector<pii>, greater<pii> >coada;

bool viz[MAXN];

int n,m;



int main()

{



    in>>n>>m;

    for(int i = 1; i <= m; i++){

        int x,y,cost;

        in>>x>>y>>cost;

        graf[x].push_back({cost,y});

        graf[y].push_back({cost,x});

    }

    viz[1] = 1;

    for(int i = 0; i < graf[1].size(); i++)

        coada.push({graf[1][i].first,{1,graf[1][i].second}});

    long long s = 0;

    vector<pair<int,int>>arbore;

    while(!coada.empty() && arbore.size() < n - 1){

        pii ceva = coada.top();

        int tata = ceva.second.first,nod = ceva.second.second;

        int cost = ceva.first;

        coada.pop();

        if(viz[nod])

            continue;

        s += cost;

        arbore.push_back({tata,nod});

        viz[nod] = true;

        for(int i = 0; i < graf[nod].size(); i++){

            int vecin = graf[nod][i].second,cost = graf[nod][i].first;

            if(!viz[vecin]){

                coada.push({cost,{nod,vecin}});

            }

        }

    }

    out<<s<<"\n"<<arbore.size()<<"\n";

    for(auto muchie : arbore)

        out<<muchie.first<<" "<<muchie.second<<"\n";



    return 0;

}
