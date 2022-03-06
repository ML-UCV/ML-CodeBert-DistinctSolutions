#include<fstream>
#include <iostream>
#include<queue>


using namespace std;

const int NMAX = 200010;

int N,M;
priority_queue< pair<int, pair<int,int> >, vector< pair<int, pair<int,int> > >, greater< pair<int, pair<int,int> > > >pq;

vector<pair<int,int>> G[NMAX], apm;
bool viz[NMAX];

int main()
{
    ifstream f("apm.in");
    ofstream g("apm.out");
    f>>N>>M;
    int s,d,c;
    for(int i=0;i<M;i++)
    {
        f>>s>>d>>c;
        G[s].push_back(make_pair(d,c));
        G[d].push_back(make_pair(s,c));
    }

    int rad = 1;
    viz[rad] = true;

    for(auto muchie: G[rad])
        pq.push(make_pair(muchie.second,make_pair(rad,muchie.first)));

    int cost = 0;

    while(!pq.empty())
    {
        pair<int,pair<int,int>> aux = pq.top();
        pq.pop();

        int c = aux.first;
        int next = aux.second.second;

        if(!viz[next])
        {
            viz[next] = true;
            cost+= c;
            apm.push_back(aux.second);

            for(auto m: G[next])
                pq.push(make_pair(m.second,make_pair(next,m.first)));

        }
    }

    g<<cost<<"\n";
   g<<apm.size()<<"\n";
    for(auto m: apm)
       g<<m.first<<" "<<m.second<<"\n";

    return 0;


}
