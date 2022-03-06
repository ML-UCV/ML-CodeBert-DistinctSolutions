#include <fstream>
#include <vector>
#include <queue>
#include <bitset>


using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");

const int N = 200001;

vector<pair<int,int>> v[N], sol;

bitset<N> used;

int n,m,x,y,c,cost;

priority_queue<pair<int,pair<int,int>>> pq;

int main()

{

    f>>n>>m;

    for(;m;m--)

    {

        f>>x>>y>>c;

        v[x].push_back(make_pair(y,c));

        v[y].push_back(make_pair(x,c));

    }

    used[1]=1;

    for(auto it:v[1])

    {

        x=it.first;

        c=it.second;

        pq.push(make_pair(-c,make_pair(1,x)));

    }

    int muchiiRamase=n-1;

    while(muchiiRamase)

    {

        c = -pq.top().first;

        x= pq.top().second.first;

        y= pq.top().second.second;

        pq.pop();

        if(used[y])

            continue;

        used[y]=1;

        cost+=c;

        sol.push_back(make_pair(x,y));

        muchiiRamase--;

        for(auto it:v[y])

        {

            x=it.first;

            c=it.second;

            if(!used[x])

                pq.push(make_pair(-c,make_pair(y,x)));

        }



    }

    g<<cost<<'\n'<<n-1<<'\n';

    for(auto it:sol)

        g<<it.first<<' '<<it.second<<'\n';

    return 0;

}
