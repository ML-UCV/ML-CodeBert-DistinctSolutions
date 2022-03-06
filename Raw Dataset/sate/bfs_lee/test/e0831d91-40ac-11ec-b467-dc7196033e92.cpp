#include <bits/stdc++.h>

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
InParser in("sate.in");
ofstream out("sate.out");
int n,m,x,y,c,d[30005],vis[30005],a,b;
vector<pair<int,int>> v[30005];
queue<int> q;
void bfs(int nod)
{
    q.push(nod);
    vis[nod]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(auto it:v[x])
        {
            if(vis[it.second]==0)
           {
            d[it.second]=d[x]+it.first;
            vis[it.second]=1;
            if(it.second==b)
            {
                out<<abs(d[it.second]);
                return ;
            }
            q.push(it.second);
           }
        }
    }
}
int main()
{
    in>>n>>m>>a>>b;
    for(int i=1;i<=m;i++)
    {
        in>>x>>y>>c;
        v[x].push_back({c,y});
        v[y].push_back({-c,x});
    }
    bfs(a);
    return 0;
}
