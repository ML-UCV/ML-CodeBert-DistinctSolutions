#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin ("apm.in");

ofstream fout ("apm.out");

vector < pair<int,int> >v[200010],vec;

priority_queue< pair<int, pair<int,int> >,vector< pair<int, pair<int,int> > >,greater< pair<int, pair<int,int> > > >pq;

pair<int, pair<int,int> > tt;

int n,m,a,b,c;

bool viz[200010];

long long cost;

int main()

{

    fin>>n>>m;

    for(;m;m--)

    {

        fin>>a>>b>>c;

        v[a].push_back(make_pair(c,b));

        v[b].push_back(make_pair(c,a));

    }

    viz[1]=1;

    for(auto it:v[1])

    {

        pq.push(make_pair(it.first,make_pair(1,it.second)));

    }



    for(int i=1;i<=n-1;i++)

    {

        while(viz[pq.top().second.second])

            pq.pop();

        tt=pq.top();

        cost+=tt.first;

        vec.push_back(make_pair(tt.second.first,tt.second.second));

        viz[tt.second.second]=1;

        for(auto it:v[tt.second.second])

        {

            if(viz[it.second]==0)

            {

                pq.push(make_pair(it.first,make_pair(tt.second.second,it.second)));

            }

        }





    }

    fout<<cost<<'\n'<<n-1<<'\n';

    for(auto it:vec)

        fout<<it.first<<" "<<it.second<<'\n';



    return 0;

}
