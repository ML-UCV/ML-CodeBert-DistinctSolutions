#include <cstdio>
#include <vector>

using namespace std;

//ifstream cin("sate.in");
//ofstream cout("sate.out");

vector<pair<int,int>>vecini[100205];
int viz[30005],dist[30005],x1,y1,d,n,m,x,y;
const int Lim = 10000000;
int u =  Lim - 1;
char s[Lim];

void Next () {
	if (++u == Lim)
		fread(s, 1, Lim, stdin), u = 0;
}

void Get (int &x)  {
	for (; s[u] < '0' || s[u] > '9'; Next());
	for (x = 0; s[u] >= '0' && s[u] <= '9'; Next())
		x = x * 10 + s[u] - '0';
}

void dfs(int nod){
    viz[nod]=1;
    for(auto i:vecini[nod]){
        if(!viz[i.first]){
            dist[i.first]=dist[nod]+i.second;
            dfs(i.first);
        }
    }
}

int main()
{
    freopen("sate.in", "r", stdin);
	freopen("sate.out", "w", stdout);
    Get(n),Get(m),Get(x),Get(y);
    for(int i=1;i<=m;i++){
        Get(x1),Get(y1),Get(d);
        vecini[x1].push_back({y1,d});
        vecini[y1].push_back({x1,-d});
    }
    viz[x]=1;
    dfs(x);
    if(viz[y]!=1){
        printf("%d",-1);
        return 0;
    }
    if(dist[y]<0){
        dist[y]*=-1;
    }
    printf("%d",dist[y]);
    return 0;
}
