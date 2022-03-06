#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream cin("sate.in");
ofstream cout("sate.out");

int n, m, a, b, D[30005];
const int inf = (1 << 30);
struct pr
{
    int dest, cost;
};

vector < vector < pr > > v;

void prep()
{
    for(int i = 1 ; i <= n ; i++)
        D[i] = inf;
    D[a] = 0;
}

void BFS()
{
    queue < int > Q;
    Q.push(a);

    while(!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        //cout << p << '\n';

        for(int i = 0 ; i < v[p].size() ; i++)
        {
            pr u = v[p][i];
            if(D[u.dest] > D[p] + u.cost)
               // cout << "INDICE \n",
                D[u.dest] = D[p] + u.cost,
                Q.push(u.dest);
        }
    }

}

void citire()
{
    int x, y, z;
    pr obiect;

    cin >> n >> m >> a >> b;

    v.resize(n + 5);
    for(int i = 1 ; i <= m ; i++)
        cin >> x >> y >> z,
        obiect.dest = y,
        obiect.cost = z, v[x].push_back(obiect),
        obiect.dest = x,
        obiect.cost =-z, v[y].push_back(obiect);
}

void rez()
{
    prep();
    BFS();

    /*for(int i = 1 ; i <= n ; i++)
        cout << i << ' ' << D[i] << '\n';*/

    cout << D[b] << '\n';
}

int main()
{
    citire();
    rez();
    return 0;
}
