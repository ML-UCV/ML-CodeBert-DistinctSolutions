#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int dist[100001];
vector<pair <int,int> >vec[100001];
queue < int > q;

int main()
{
    int N,M,X,Y,i,j,D;
    f>>N>>M>>X>>Y;
    for(int h=1;h<=M;h++)
    {
        f>>i>>j>>D;
        vec[i].push_back({j,D});
        vec[j].push_back({i,D});
    }
    q.push(X);
    while(!q.empty())
    {
        X=q.front();
        q.pop();
        for(int h=0;h<vec[X].size();h++)
        {
            if(dist[vec[X][h].first]==0 && vec[X][h].first!=X)
            {
                q.push(vec[X][h].first);
                if(X<vec[X][h].first)
                    dist[vec[X][h].first]=vec[X][h].second+dist[X];
                else
                    dist[vec[X][h].first]=dist[X]-vec[X][h].second;
            }

        }
    }
    g<<dist[Y];
    return 0;
}
