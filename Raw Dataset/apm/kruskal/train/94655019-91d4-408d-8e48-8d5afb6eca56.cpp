#include <bits/stdc++.h>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



int n, m;

vector < pair<int, pair<int, int > > > edge;

vector<int> ans;

int t[200001];



int Find(int x)

{

    int rx = x, y;

    while (t[rx] != 0)rx = t[rx];

    while (x != rx)

    {

        y = t[x];

        t[x] = rx;

        x = y;

    }

    return rx;

}

void Union(int x, int y)

{

    t[y] = x;

}

int main()

{

    int x, y, c;

    fin >> n >> m;

    while (m--)

    {

        fin >> x >> y >> c;

        edge.push_back({ c, {x, y} });

    }



    sort(edge.begin(), edge.end());

    int cost = 0;

    for (unsigned int i = 0; i < edge.size(); i++)

    {

        int x = Find(edge[i].second.first);

        int y = Find(edge[i].second.second);

        if (x != y)

        {

            Union(x, y);

            cost += edge[i].first;

            ans.push_back(i);

        }

    }

    fout << cost << "\n";

    fout << ans.size() << "\n";

    for (unsigned int i = 0; i < ans.size(); i++)

        fout << edge[ans[i]].second.first << " " << edge[ans[i]].second.second << "\n";



    fin.close();

    fout.close();

    return 0;

}
