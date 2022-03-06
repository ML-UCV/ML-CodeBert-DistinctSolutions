#include <bits/stdc++.h>
using namespace std;
 
ifstream in("sate.in");
ofstream out("sate.out");

vector< pair< int, int > > G[30010];
int distante[30010], n, m, sat1, sat2;
	
int BFS() {
	queue< int > q; q.push(sat1);

	distante[sat1] = 0;
	while(!q.empty()) {
		if(distante[sat2] != 0) {
			return distante[sat2];
		}

		int tempNode = q.front(); q.pop();

		for(auto vecin: G[tempNode]) {
			if(distante[vecin.first] == 0) {
				if(tempNode < vecin.first) {
					distante[vecin.first] = distante[tempNode] + vecin.second;
				} else {
					distante[vecin.first] = distante[tempNode] - vecin.second;
				}
				q.push(vecin.first);
			}	
		}
	}
	return 0;
}

int main() {

	in >> n >> m >> sat1 >> sat2;

	for(int i = 1; i <= m; ++i) {
		int  x, y, d; in >> x >> y >> d;
		G[x].push_back({y, d});
		G[y].push_back({x, d});
	}
	out << BFS();

    in.close(); out.close();
 
    return 0;
}