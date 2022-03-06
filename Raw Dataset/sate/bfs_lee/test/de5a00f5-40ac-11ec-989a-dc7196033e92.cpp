#include <stdio.h>
#include <queue>
#include <vector>
#include <ctype.h>
using namespace std;
struct Muchie
{
    int y,z;
};
vector<Muchie> g[30005];
int dist[30005];
bool viz[30005];
queue<int> q;
/** FuncÅ£iile necesare parsÄrii fiÅierului de intrare **/
FILE *fin, *fout;
int _in_loc; char _in_buff[4096];


void read_init(const char* nume) // ApelaÅ£i aceastÄ funcÅ£ie la Ã®nceputul funcÅ£iei <main>
{
	fin = fopen(nume, "r");
	_in_loc = 4095;
}

char read_ch()
{
	++_in_loc;
	if (_in_loc == 4096) {
		_in_loc = 0;
		fread(_in_buff, 1, 4096, fin);
	}
	return _in_buff[_in_loc];
}

int read_u32() // ApelaÅ£i aceastÄ funcÅ£ie pentru a citi un numÄr ce se Ã®ncadreazÄ Ã®n categoria <unsigned int>
{
	int u32 = 0; char c;
	while (!isdigit(c = read_ch()) && c != '-');
	int sgn = 1;
	if (c == '-') {
		sgn = -1;
	} else {
		u32 = c - '0';
	}
	while (isdigit(c = read_ch())) {
		u32 = u32 * 10 + c - '0';
	}
	return u32 * sgn;
}
int bfs(int start, int finish)
{
    q.push(start);
    dist[start]=0;
    viz[start]=1;
    while(!q.empty() && dist[finish]==0){
        int u=q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++)
            if(viz[g[u][i].y]==0){
                if(u>g[u][i].y)
                    dist[g[u][i].y]=dist[u]-g[u][i].z;
                else
                    dist[g[u][i].y]=dist[u]+g[u][i].z;
                viz[g[u][i].y]=1;
                q.push(g[u][i].y);
            }
    }
    return dist[finish];
}
int main()
{   read_init("sate.in");
    fout=fopen("sate.out", "w");
    int n,m,x,y,x1,y1,z,i;
    n=read_u32();
    m=read_u32();
    x=read_u32();
    y=read_u32();
    for(i=1; i<=m; i++){
        x1=read_u32();
        y1=read_u32();
        z=read_u32();
        g[x1].push_back({y1, z});
        g[y1].push_back({x1, z});
    }
    fprintf(fout, "%d", bfs(x, y));
    return 0;
}
