#include <algorithm>
#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
using namespace std;

ifstream in("ctc.in");

ofstream out("ctc.out");

const int maxn = 100005;

vector <int> ctc[maxn];

vector <int> v[maxn];

vector <int> u[maxn];

vector <int> ord;

bitset <maxn> viz;

bitset <maxn> Ass;



void dfs(int nod)

{

    viz[nod] = 1;

    for(auto it : v[nod])

        if(!viz[it])

            dfs(it);

    ord.push_back(nod);

}



void Assign(int nod, int rad)

{

    Ass[nod] = 1;

    ctc[rad].push_back(nod);

    for(auto it : u[nod])

        if(!Ass[it])

            Assign(it, rad);

}



int main()

{

    int n, m;

    in >> n >> m;

    for(int i = 1; i <= m; i++)

    {

        int x, y;

        in >> x >> y;

        v[x].push_back(y);

        u[y].push_back(x);

    }

    for(int i = 1; i <= n; i++)

        if(!viz[i])

            dfs(i);

    reverse(ord.begin(), ord.end());

    int comp = 0;

    for(auto it : ord)

        if(!Ass[it])

            Assign(it, ++comp);

    out << comp << "\n";

    for(int i = 1; i <= comp; i++, out << "\n")

        for(auto it : ctc[i])

            out << it << " ";

    return 0;

}
