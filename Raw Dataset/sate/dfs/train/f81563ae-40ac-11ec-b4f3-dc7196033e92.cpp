#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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
InParser fin("sate.in");
ofstream fout("sate.out");
int n,m,x,y,i,dist,stg,s,xi,yi;
int d[30009];
vector <pair <int,int> >v[30009];
void dfs(int nod)
{
    if(nod==yi)
    {
        fout<<dist;
        stg=1;
        return;
    }
    d[nod]=1;
    for(int i=0;i<v[nod].size()&&stg==0;i++)
    {
        if(!d[v[nod][i].second])
        {
            dist+=v[nod][i].first;
            dfs(v[nod][i].second);
            dist-=v[nod][i].first;
        }
    }
}
int main()
{
    fin>>n>>m>>xi>>yi;
    for(i=1;i<=m;i++)
    {
        fin>>x>>y>>s;
        v[x].pb(mp(s,y));
        v[y].pb(mp(-s,x));
    }
    dfs(xi);
    return 0;
}
