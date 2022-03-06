#include<bits/stdc++.h>
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


InParser  f("sate.in");
ofstream g("sate.out");
int n,m,start,finish,ras;
vector< pair<int,int> > G[30001];
queue<int> Q;
int dp[30001];
void BFS()
{
    Q.push(start);
    dp[start]=1;
    while(!Q.empty())
    {
        int node=Q.front();
        Q.pop();
        for(vector< pair <int, int> >::iterator it=G[node].begin();it<G[node].end();++it)
        {
            pair<int,int> i=*it;
            if(dp[i.first]==0)
            {
                dp[i.first]=dp[node]+i.second;
                Q.push(i.first);
            }
            if(i.first==finish)
                return;
        }
    }
}
int main()
{

    f>>n>>m>>start>>finish;
    while(m--)
    {
        int a,b,v;
        f>>a>>b>>v;
        G[a].push_back({b, v});
        G[b].push_back({a, -v});
    }
    BFS();
    g<<dp[finish]-1;
}
