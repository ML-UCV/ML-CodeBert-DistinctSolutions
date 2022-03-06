#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream cin("apm.in");
ofstream cout("apm.out");
struct chestie
{
    int a,b ,cost;
}v[2000001];
vector <pair<int,int>> sol;
int costmin;
bool cond(chestie x, chestie y)
{
    return x.cost <y.cost;
}
int tata[2000001],height[2000001];
int n,m ;
int FIND(int);
void Union(int,int);
int main() {
    cin >> n >> m;
    for(int i =1 ;i <=m;i ++)
        cin >> v[i].a >> v[i].b>>v[i] .cost;
    sort(v + 1, v + m + 1, cond);
    int contor = 0;
    for( int i =1 ;i <=m; i ++)
    {
        int x = FIND(v[i].a);
        int y = FIND(v[i].b);
        if(x != y)
        {
            Union(x, y);
            costmin += v[i].cost;
            sol.push_back({v[i].a,v[i].b});
            if(sol.size() == n -1)
                break;
        }
    }
    cout << costmin<<'\n'<<sol.size()<<'\n';
    for(auto i:sol)
        cout << i.first << " "<<i.second<<'\n';
    return 0;
}
int FIND(int x)
{
    if(tata[x] == 0)
        return x;
    int cx =x;
    while(tata[x])
        x=tata[x];
    while(tata[cx] != x)
    {
        int aux = cx;
        cx = tata[cx];
        tata[aux] = x;
    }
    return x;
}
void Union(int x, int y)
{
    if(height[x] > height[y])
    {
        tata[y] =x;
    } else
        if(height[x] <height[y])
            tata[x] = y;
        else
        {
            tata[x] = y;
            height[y] ++;
        }
}
