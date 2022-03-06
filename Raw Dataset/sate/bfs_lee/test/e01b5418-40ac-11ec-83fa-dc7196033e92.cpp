#include <bits/stdc++.h>
using namespace std;

class InParser
{
private:
    FILE *fin;
    char *buff;
    int sp;

    char read_ch()
    {
        ++sp;
        if (sp == 4096)
        {
            sp = 0;
            fread(buff, 1, 4096, fin);
        }
        return buff[sp];
    }

public:
    InParser(const char* nume)
    {
        fin = fopen(nume, "r");
        buff = new char[4096]();
        sp = 4095;
    }

    InParser& operator >> (int &n)
    {
        char c;
        while (!isdigit(c = read_ch()) && c != '-');
        int sgn = 1;
        if (c == '-')
        {
            n = 0;
            sgn = -1;
        }
        else
        {
            n = c - '0';
        }
        while (isdigit(c = read_ch()))
        {
            n = 10 * n + c - '0';
        }
        n *= sgn;
        return *this;
    }

    InParser& operator >> (long long &n)
    {
        char c;
        n = 0;
        while (!isdigit(c = read_ch()) && c != '-');
        long long sgn = 1;
        if (c == '-')
        {
            n = 0;
            sgn = -1;
        }
        else
        {
            n = c - '0';
        }
        while (isdigit(c = read_ch()))
        {
            n = 10 * n + c - '0';
        }
        n *= sgn;
        return *this;
    }
};

InParser in("sate.in");
ofstream out("sate.out");
const int nmax=3e4+5;
int N, M, X, Y, i, x, y, dist, neig, len, d[nmax];
vector <pair<int,int>> G[nmax];
bitset <nmax> viz;
queue <int> Q;

void BFS(int nod)
{
    viz[nod]=1;
    Q.push(nod);
    while(!Q.empty())
    {
        nod=Q.front();
        for(i=0; i<G[nod].size(); i++)
        {
            neig=G[nod][i].first;
            len=G[nod][i].second;
            if(!viz[neig])
            {
                d[neig]=d[nod]+len;
                viz[neig]=1;
                Q.push(neig);
            }
        }
        Q.pop();
    }
}

int main()
{
    in >> N >> M >> X >> Y;
    for(i=1; i<=M; i++)
    {
        in >> x >> y >> dist;
        G[x].push_back({y,dist});
        G[y].push_back({x,-dist});
    }
    BFS(X);
    out << d[Y];
}
