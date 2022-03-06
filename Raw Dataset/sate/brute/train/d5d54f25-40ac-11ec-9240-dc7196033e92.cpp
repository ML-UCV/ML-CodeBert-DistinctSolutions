//#include <iostream>
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
} in ("sate.in");
ofstream out("sate.out");
vector<pair<int,int> > v[30005];
int q[30005];
int d[30005],sz=1,cur=1;
int main()
{
    int n,m,x,y,a,b,di;
    in>>n>>m>>x>>y;
    for(int i=1;i<=m;i++){
        in>>a>>b>>di;
        v[a].push_back(make_pair(b,di));
        v[b].push_back(make_pair(a,-di));
    }
    for(int i=1;i<=n;i++){
        d[i]=30000000;
    }
    q[1]=x;
    d[x]=0;
    while(cur<=sz){
        a=q[cur];
        cur++;
        for(auto u:v[a]){
            if(d[u.first]==30000000){
                d[u.first]=d[a]+u.second;
                if(u.first==y){
                    out<<d[y];
                    return 0;
                }
                q[++sz]=u.first;
            }
        }
    }
    return 0;
}
