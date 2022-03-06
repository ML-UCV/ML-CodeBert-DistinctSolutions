#include<bits/stdc++.h>
#define fi first
#define sc second
using namespace std;
#include <stdio.h>
#include <ctype.h>

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
} f("sate.in");
ofstream g("sate.out");
int n, m, x, y;
vector<pair<int, int>>v[30001];
int dis[30001];
bool viz[30001];
deque<int>d;
void Bfs(int nod)
{
    viz[nod]=1;
    d.push_back(nod);
    while(!d.empty())
    {
        nod=d.front();
        d.pop_front();
        for(int i=0; i<v[nod].size(); i++)
        {
            if(!viz[v[nod][i].fi])
            {
                d.push_back(v[nod][i].fi);
                viz[v[nod][i].fi]=1;
                dis[v[nod][i].fi]=dis[nod]+v[nod][i].sc;
            }
        }
    }
}
int main()
{
    f>>n>>m>>x>>y;
    for(int i=1; i<=m; i++)
    {
        int a, b, cost;
        f>>a>>b>>cost;
        v[a].push_back(make_pair(b, cost));
        v[b].push_back(make_pair(a, -cost));
    }
    Bfs(x);
    g<<dis[y];
    return 0;
}
