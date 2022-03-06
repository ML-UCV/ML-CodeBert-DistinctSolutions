#include <bits/stdc++.h>

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int n, m, x, y, a, b, c, dist[30005], l, ind;
char c1[25], c2[25], c3[25];
vector <pair<int,int> > v[30005];

int rez()
{
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int x1 = q.front();
        q.pop();
        for(auto i:v[x1])
        {
            if(dist[i.first] == 0)
            {
                dist[i.first] = dist[x1]+i.second;
                q.push(i.first);
                if(i.first == y)
                    return dist[y];
            }
        }
    }
}
int main()
{
    f >> n >> m >> x >> y;
	f.get();
    for(int i = 1; i <= m; ++i)
    {
        f >> c1 >> c2 >> c3;
        a = 0, b = 0, c = 0;
        ind = 0;

        while(isdigit(c1[ind]))
            a = a*10 + c1[ind++] - '0';

        ind = 0;
        while(isdigit(c2[ind]))
            b = b*10 + c2[ind++] - '0';

        ind = 0;
        while(isdigit(c3[ind]))
            c = c*10 + c3[ind++] - '0';

        v[a].push_back({b,c});
        v[b].push_back({a,-c});
    }

    g<<rez();
    return 0;
}
