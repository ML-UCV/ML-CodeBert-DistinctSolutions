#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;
 
const int n_max = 30009;
vector < pair < int, int> > v[n_max];
int cost[n_max],
    vaz[n_max],
    s[n_max];
int i, m, n, left, right, x, y, a, b, c;
void process(int x)
{
    vector < pair < int, int> >::iterator it;
    int t;
    for (it = v[x].begin(); it != v[x].end(); ++ it)
        if (!vaz[(*it).first])
        {
            s[++right] = (*it).first;
            if (x > (*it).first) 
                t = -1;
            else
                t = 1;
            cost[(*it).first] = cost[x] + ((*it).second * t);
            vaz[(*it).first] = 1;
        }
}
 
int main()
{
    freopen("sate.in","r",stdin);
    freopen("sate.out","w",stdout);
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (i = 1; i <= m; ++ i)
    {
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    } 
    left = 0;
    right = 1;
    s[right] = x;
    vaz[x] = 1;
    while (left < right && !vaz[y])
    {
        ++left;
        process(s[left]);
    }
    printf("%d\n",cost[y]);
    return 0;
}
