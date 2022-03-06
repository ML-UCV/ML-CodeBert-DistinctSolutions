#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <cstring>

#define sat_dist std::pair<int,int>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

int n,m,x,y;    
vector<sat_dist> vec[100002];
queue<int> coada;
int distante[100002];

int main()
{
    memset(distante,-1,sizeof(distante));
    int sat,sat_conect, distance,nod;
    fin>>n>>m>>x>>y;
    for(int i=0;i<m;i++)
    {
        fin>>sat>>sat_conect>>distance;
        vec[sat].push_back(make_pair(sat_conect,distance));
        vec[sat_conect].push_back(make_pair(sat,distance));
    }
    distante[x]=0;
    coada.push(x);
    while(!coada.empty())
    {
        nod=coada.front();
        for(int i=0;i<vec[nod].size();i++)
        {
            if(distante[vec[nod][i].first]==-1)
            {
                if(nod<vec[nod][i].first)
                distante[vec[nod][i].first]=distante[nod]+vec[nod][i].second;
                else
                distante[vec[nod][i].first]=distante[nod]-vec[nod][i].second;
                coada.push(vec[nod][i].first);
            }
        }
        coada.pop();
    }
    fout<<distante[y];
    fin.close();
    fout.close();
    return 0;
}