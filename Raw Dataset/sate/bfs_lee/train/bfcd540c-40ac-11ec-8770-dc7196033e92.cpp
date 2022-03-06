#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int  NMAX = 30001;
vector<pair<int, int>> graf[NMAX];
int x, y, ok=1;
bool vizitat[NMAX];
queue<int> coada;
int distanta[NMAX];



void BFS(int x) {
	coada.push(x);
	vizitat[x] = true;
	while (!coada.empty() && ok==1) {
		int curr = coada.front();
		coada.pop();
		for (int i = 0; i < graf[curr].size() && ok==1; i++) {
			if (!vizitat[graf[curr][i].first]) {
				vizitat[graf[curr][i].first] = true;
				coada.push(graf[curr][i].first);
				if (curr < graf[curr][i].first) 
					distanta[graf[curr][i].first] = distanta[curr] + graf[curr][i].second;
				else
					distanta[graf[curr][i].first] = distanta[curr] - graf[curr][i].second;
			}
		}
	}

}

int main() {
	ifstream in("sate.in");
	ofstream out("sate.out");
	int n, m, a, b, d;
	in >> n >> m >> x >> y;


	for (int i = 0; i < m; i++) {
		in >> a >> b >> d;
		graf[a].push_back(make_pair(b, d));
		graf[b].push_back(make_pair(a, d));
	}
	distanta[x] = 0;

	graf[x].push_back(make_pair(x, 0));

	BFS(x);

	out << distanta[y];

	return 0;
}