#include<fstream>
#include<vector>
#include<set>
using namespace std;

ifstream cin("apm.in");

ofstream cout("apm.out");

struct muchie

{

    int cost;

    int elem;

};

struct ura

{

    int ct;

    int nod1;

    int nod2;

};

bool operator < (const ura& lhs, const ura& rhs)

{

    return (lhs.ct) < (rhs.ct);

}



vector<vector<muchie>> v;

vector<pair<int, int>> raspuns;

multiset<ura> costuri;

bool viz[200001];

int main()

{

    int n, m, x, y, c, k, j, s;

    cin>>n>>m;

    v.resize(n+1);

    for(int i=1; i<=m; i++)

    {

        cin>>x>>y>>c;

        v[x].push_back({c, y});

        v[y].push_back({c, x});

    }

    s=0;

    k=n;

    j=1;

    viz[1]=true;

    while(k>1)

    {

        for(size_t i=0; i<v[j].size(); i++)

        {

            costuri.insert({v[j][i].cost, j, v[j][i].elem});

        }

        while(viz[(*costuri.begin()).nod2] == true)

            costuri.erase(costuri.begin());

        auto it=costuri.begin();

        raspuns.push_back({(*it).nod1, (*it).nod2});

        j=(*it).nod2;

        s+=(*it).ct;

        viz[j]=true;

        costuri.erase(costuri.begin());

        k--;

    }

    cout<<s<<'\n'<<raspuns.size()<<'\n';

    for(size_t i=0; i<raspuns.size(); i++)

    {

        cout<<raspuns[i].first<<" "<<raspuns[i].second<<'\n';

    }

    return 0;

}
