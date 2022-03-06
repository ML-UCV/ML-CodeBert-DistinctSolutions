#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

ifstream fin("dmin.in");
ofstream fout("dmin.out");

int n, m;
typedef pair <double, int> nod;
vector <double> d(1505, 1 << 30);
vector <nod> a[1505];
vector <int> fr(1505, 0);
vector <bool> viz(1505);
queue <int> q;

int main()
{
    fin>>n>>m;
    while(m--)
    {
        int x, second;
        double first, c2;
        fin>>x>>second>>first;
        c2 = log10(first);
        a[x].push_back(nod(c2, second));
        a[second].push_back(nod(c2, x));
    }

    q.push(1);
    d[1] = 0;
    fr[1] = 1;
    viz[1] = 1;
    while(!q.empty())
    {
        int x = q.front();
        viz[x] = 0;
        q.pop();
        for(unsigned i=0; i<a[x].size(); i++)
            if(abs(d[x] + a[x][i].first - d[a[x][i].second]) <= 0.0000000001)
            {
                fr[a[x][i].second] += fr[x];
                fr[a[x][i].second] %= 104659;
            }
            else if(d[x] + a[x][i].first < d[a[x][i].second])
            {
                d[a[x][i].second] = d[x] + a[x][i].first;
                fr[a[x][i].second] = fr[x]%104659;
                if(!viz[a[x][i].second]) q.push(a[x][i].second), viz[a[x][i].second] = 1;;
            }
    }

    for(int i=2; i<=n; i++)
        fout<<fr[i]<<' ';
    return 0;
}
