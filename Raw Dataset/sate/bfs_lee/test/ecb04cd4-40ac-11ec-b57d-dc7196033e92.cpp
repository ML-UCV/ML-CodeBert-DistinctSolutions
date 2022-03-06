#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

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

vector < pair<int,int> > graph[30005];
queue <int> q;
int n,m,a,b,x,y,c,d[30005],i;
int main()
{
    InParser f("sate.in");
    ofstream g("sate.out");
    f>>n>>m>>a>>b;
    while(m--)
    {
        f>>x>>y>>c;
        graph[x].push_back({y,c});
        graph[y].push_back({x,-c});
    }
    for(i=1;i<=n;i++)
    {
        d[i]=1e9;
    }
    if(a>b)
        swap(a,b);
    q.push(a);
    d[a]=0;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(i=0;i<(int)graph[x].size();i++)
        {
            if(d[graph[x][i].first]>d[x]+graph[x][i].second)
            {
                d[graph[x][i].first]=d[x]+graph[x][i].second;
                q.push(graph[x][i].first);
            }
        }
    }
    g<<d[b];
    return 0;
}
