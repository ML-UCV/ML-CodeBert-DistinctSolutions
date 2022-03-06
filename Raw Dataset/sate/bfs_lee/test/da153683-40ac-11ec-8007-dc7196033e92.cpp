#include <iostream>
#include <fstream>
#include <queue>
#define NMAX 30000

using namespace std;

ofstream g("sate.out");

int n, m, x, y, dist[NMAX+10];
bool viz[NMAX+10];
vector <pair <int, int> > nod[NMAX+10];
queue <int> Q;

class InParser {
private:
	FILE *fin;
	char *buff;
	int sp;

	char read_ch() {
		++sp;
		if (sp == 4096) {
			sp = 0;
			fread(buff, 1, 4096, fin);
		}
		return buff[sp];
	}

public:
	InParser(const char* nume) {
		fin = fopen(nume, "r");
		buff = new char[4096]();
		sp = 4095;
	}

	InParser& operator >> (int &n) {
		char c;
		while (!isdigit(c = read_ch()) && c != '-');
		int sgn = 1;
		if (c == '-') {
			n = 0;
			sgn = -1;
		} else {
			n = c - '0';
		}
		while (isdigit(c = read_ch())) {
			n = 10 * n + c - '0';
		}
		n *= sgn;
		return *this;
	}

	InParser& operator >> (long long &n) {
		char c;
		n = 0;
		while (!isdigit(c = read_ch()) && c != '-');
		long long sgn = 1;
		if (c == '-') {
			n = 0;
			sgn = -1;
		} else {
			n = c - '0';
		}
		while (isdigit(c = read_ch())) {
			n = 10 * n + c - '0';
		}
		n *= sgn;
		return *this;
	}
};

void bfs(int val)
{   viz[val] = 1;
    Q.push(val);
    while(!Q.empty())
        {   val = Q.front();
            Q.pop();

            if(val == y) return;
            for(int i=0; i<nod[val].size(); i++)
                if(!viz[nod[val][i].second])
                    {   dist[nod[val][i].second] = dist[val] + nod[val][i].first;
                        viz[nod[val][i].second] = 1;
                        Q.push(nod[val][i].second);
                    }
        }
}

int main()
{
    InParser f("sate.in");
    f >> n >> m >> x >> y;
    if(x > y) swap(x, y);
    for(int i=1; i<=m; i++)
        {   int nod1, nod2, cost;
            f >> nod1 >> nod2 >> cost;
            if(nod1 > nod2) swap(nod1, nod2);
            nod[nod1].push_back(make_pair(cost, nod2));
            nod[nod2].push_back(make_pair(-cost, nod1));
        }
    bfs(x);
    g << dist[y] << '\n';
    return 0;
}
