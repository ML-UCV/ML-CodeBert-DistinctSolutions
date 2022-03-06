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

void add(int);

int main()

{

    f>>n>>m;

    for(;m;m--)

    {

        f>>x>>y>>c;

        v[x].push_back(make_pair(y,c));

        v[y].push_back(make_pair(x,c));

    }

    add(1);

    int muchiiRamase=n-1;

    while(muchiiRamase)

    {

        tie(c,x,y)=pq.top();

        pq.pop();

        if(used[y])

            continue;

        cost-=c;

        sol.push_back(make_pair(x,y));

        muchiiRamase--;

        add(y);

    }

    g<<cost<<'\n'<<n-1<<'\n';

    for(auto it:sol)

        g<<it.first<<' '<<it.second<<'\n';

    return 0;

}

void add(int nod)

{

    used[nod]=1;

    for(auto it:v[nod])

    {

        int vec,cst;

        tie(vec,cst)=it;

        if(!used[vec])

            pq.push(make_tuple(-cst,nod,vec));

    }

}
