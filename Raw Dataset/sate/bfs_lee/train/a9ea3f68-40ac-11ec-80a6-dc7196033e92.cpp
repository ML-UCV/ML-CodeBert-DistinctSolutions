#include <fstream>
#include <set>
#include <queue>

using namespace std;

ifstream cin("sate.in");
ofstream cout("sate.out");

using pii = pair<int, int>;
const int N = 30005;

set<pii> graf[N];
bool beenThere[N];


int main() {
	int n, m, X, Y;
	cin >> n >> m >> X >> Y;
	for (int i = 1; i <= m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		graf[x].insert({ y, d });
		graf[y].insert({ x, -d });
	}
	queue<pii> q;
	q.push({ X, 0 });
	beenThere[X] = true;
	while (!q.empty()) {
		pii &now = q.front();
		beenThere[now.first] = true;
		if (now.first == Y) {
			cout << now.second;
			return 0;
		}
		for (pii i : graf[now.first]) {
			if(!beenThere[i.first])
			q.push({ i.first, now.second + i.second});
		}
		q.pop();
	}
	return 0;
}