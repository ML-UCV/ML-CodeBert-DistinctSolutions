#include <bits/stdc++.h>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

int n, m;
int x, y;
int ans[30303];

vector<pair<int,int>> v[30303];
queue<int> coada;

int main()
{
    fin >> n >> m;
    fin >> x >> y;
    while(m--)
    {
        int a, b, c;
        fin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, -c});
        /// orasele sunt coliniare si de exemplu daca de la orasul 1 la orasul 7 face 8 km
        /// si de la orasul 7 la orasul 5 face 3 km
        /// eu ca sa ajung la orasul prefer sa merg direct de la 7 la 5
        /// adica sa tin minte costul de la orasul 7 la orasul 5 ca -3
    }
    for(int i = 1; i <= n; i ++)
    {
        ans[i] = 1e9;
    }
    coada.push(x);
    ans[x] = 0;
    while(!coada.empty())
    {
        int nod = coada.front();
        coada.pop();
        for(auto it : v[nod])
        {
            if(ans[nod] + it.second < ans[it.first])
            {
                ans[it.first] = ans[nod] + it.second;
                coada.push(it.first);
            }
        }
    }
    fout << ans[y] << '\n';
}
