#include <fstream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<pair<int,int> > graph[30005];
queue<int> q;
int dst[30005];

int BFS(int s,int d) {
	int u;

	dst[s]=0;
	q.push(s);

	while (!q.empty()) {
		if (dst[d])
			return dst[d];

		u=q.front();
		for (int v=0;v<graph[u].size();v++) {
			if (!dst[graph[u][v].first]) {
				if (u<graph[u][v].first)
					dst[graph[u][v].first]=dst[u]+graph[u][v].second;
				else
					dst[graph[u][v].first]=dst[u]-graph[u][v].second;

				q.push(graph[u][v].first);
			}
		}

		q.pop();
	}
} 

int main() {
	int n,m,s,d,x,y,c;

	ifstream in("sate.in");
	ofstream out("sate.out");

	in>>n>>m>>s>>d;

	for (int i=0;i<m;i++) {
		in>>x>>y>>c;
		graph[x].push_back(make_pair(y,c));
		graph[y].push_back(make_pair(x,c));
	}

	memset(dst,0,sizeof(dst));

	out<<BFS(s,d);

	return 0;
}