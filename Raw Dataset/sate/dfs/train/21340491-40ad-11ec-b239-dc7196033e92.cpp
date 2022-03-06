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
}f("sate.in");
ofstream g("sate.out");
int n,m,x,y;
int dmin=1e8;
vector<int>v[30002];
bool afa[30002];
void dfs(int nod,int dsf)
{
    if(nod==y)
    {
        dmin=min(dmin,dsf);
        return;
    }
    for(int i=0;i<v[nod].size();i+=2){
        if(afa[v[nod][i]]==0){
            afa[v[nod][i]]=1;
            dfs(v[nod][i],dsf+v[nod][i+1]);
        }
    }
    afa[nod]=1;
}
int main()
{
    f>>n>>m>>x>>y;
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        f>>a>>b>>c;
        v[a].push_back(b);
        v[a].push_back(c);
        v[b].push_back(a);
        v[b].push_back(-c);
    }
    dfs(x,0);
    g<<dmin;
    return 0;
}
