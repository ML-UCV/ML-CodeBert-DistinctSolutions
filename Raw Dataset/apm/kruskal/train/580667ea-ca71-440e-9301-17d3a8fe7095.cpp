#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream cin("apm.in");
ofstream cout("apm.out");



int n, m, k;
struct vertex{
    int x, y, c;
}graph[200005];

bool comp(vertex a, vertex b)
{
    return a.c < b.c;
}

int cost;
int rang[200005], father[200005];
vector<int> ans[200005];


int find(int nod)
{
    while(nod != father[nod])
        nod = father[nod];

    return nod;
}

void kruskal(){
    for(int i = 1; i <= m; i++)
    {
        int x = find(graph[i].x), y = find(graph[i].y);
        if(x != y)
        {
            if(rang[x] < rang[y])
                father[x] = y;
            if(rang[y] < rang[x])
                father[y] = x;
            if(rang[y] == rang[x])
            {
                father[x] = y;
                rang[y]++;
            }
            k++;
            ans[k].push_back(graph[i].x);
            ans[k].push_back(graph[i].y);
            cost += graph[i].c;
        }
    }

}

int main() {

    cin >> n >> m;

    for(int i = 1; i <= m; i++)
        cin >> graph[i].x >> graph[i].y >> graph[i].c;

    sort(graph+1, graph+m+1, comp);

    for(int i = 1; i <= m; i++)
    {
        rang[i] = 1;
        father[i] = i;
    }

    kruskal();

    cout << cost << "\n";
    cout << k << "\n";

    for(int i = 1; i <= k; i++)
    cout << ans[i][0] << " " << ans[i][1] << "\n";

}
