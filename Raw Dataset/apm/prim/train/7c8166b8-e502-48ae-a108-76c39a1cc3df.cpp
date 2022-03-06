#include <fstream>
#include <vector>
#include <set>




using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");



struct muchie

{

    int nod, cost;

    bool operator < (const muchie& other) const

    {

        return cost < other.cost;

    }

};



multiset<muchie> s;

vector<muchie> v[200000 +5];

int viz[200000 +5], C[200000 +5], n, m, total;

int cor[200000 +5];

vector<pair<int, int>> sol;



void ins_apm(int nod)

{

    viz[nod]=1;

    for(muchie& i : v[nod]) if(i.cost < C[i.nod])

    {

        C[i.nod] = i.cost;

        s.insert(i);

        cor[i.nod] = nod;

    }

}



int main()

{

    in>>n>>m;

    for(int i=1; i<=m; i++)

    {

        int x, y, c;

        in>>x>>y>>c;

        v[x].push_back({y, c});

        v[y].push_back({x, c});

    }

    for(int i=1; i<=n; i++) C[i]=2e9;



    ins_apm(1);

    for(int i=2; i<=n; i++)

    {

        int x = s.begin()->nod;

        while(viz[x]==1)

        {

            s.erase(s.begin());

            x = s.begin()->nod;

        }

        s.erase(s.begin());

        ins_apm(x);

        total += C[x];

        sol.push_back(make_pair(x, cor[x]));

    }



    out<<total<<'\n'<<n-1<<'\n';

    for(auto& i : sol) out<<i.first<<' '<<i.second<<'\n';

    return 0;

}
