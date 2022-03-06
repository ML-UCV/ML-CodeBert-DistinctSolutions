#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#include <tuple>


using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");

const int N = 200001;

vector<pair<int,int>> v[N], sol;

bitset<N> used;

int n,m,x,y,c,cost;

priority_queue<tuple<int,int,int>> pq;

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

        tie(x,c)=it;

        pq.push(make_tuple(-c,1,x));

    }

    int muchiiRamase=n-1;

    while(muchiiRamase)

    {

        tie(c,x,y)=pq.top();c=-c;;

        pq.pop();

        if(used[y])

            continue;

        used[y]=1;

        cost+=c;

        sol.push_back(make_pair(x,y));

        muchiiRamase--;

        for(auto it:v[y])

        {

            tie(x,c)=it;

            if(!used[x])

                pq.push(make_tuple(-c,y,x));

        }



    }

    g<<cost<<'\n'<<n-1<<'\n';

    for(auto it:sol)

        g<<it.first<<' '<<it.second<<'\n';

    return 0;

}
