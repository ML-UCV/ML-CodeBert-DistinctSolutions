#include <fstream>
#include <math.h>
#include <set>
#include <queue>

using namespace std;

ifstream fin ("apm.in");
ofstream fout ("apm.out");

int f[200001], pereche[200001], cost[200001], n, m;
int cost_total;

struct tip{
    int nod, ct;

    bool operator <(const tip &other) const{
        return ct < other.ct;
    };

};

vector <tip> l[200001];
multiset <tip> stiva;

struct tip2{
    int x, y;
}final[200001];

void intro_apm(int nod)
{
    int x, c, i;
    f[nod] = 1;

    for (i = 0; i< l[nod].size(); i++)
    {
        x = l[nod][i].nod;
        c = l[nod][i].ct;
        if(cost[x] > c)
        {
            cost[x] = c;
            stiva.insert(l[nod][i]);
            pereche[x] = nod;
        }
    }

}

int main()
{
    int C, i, j, x, y;
    fin >> n >> m;

    for (i = 2; i<= n; i++)
        cost[i] = 2000000001;

    for (i = 1; i<= m; i++)
    {
        fin >> x >> y >> C;
        l[x].push_back({y, C});
        l[y].push_back({x, C});
    }

    for (i = 2; i <= n; i++)
        stiva.insert({i, cost[i]});

    intro_apm(1);

    for (i = 2; i<= n; i++)
    {
        x = stiva.begin()->nod;
        while (f[x] == 1)
        {
            stiva.erase(stiva.begin());
            x = stiva.begin()->nod;
        }
        stiva.erase(stiva.begin());
        intro_apm(x);

        cost_total += cost[x];
        final[i-1].x = x;
        final[i-1].y = pereche[x];
    }

        fout << cost_total << '\n' << n-1 << '\n';
        for (i = 1; i<= n-1; i++)
            fout << final[i].x << " " << final[i].y << '\n';
}
