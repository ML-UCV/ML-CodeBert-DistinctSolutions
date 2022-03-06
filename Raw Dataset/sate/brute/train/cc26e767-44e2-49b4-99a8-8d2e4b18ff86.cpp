#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

vector < vector< pair < int, int > > > w;

bool b[30002];
int Y, s;

void parcurgere(int x,int s)
{
  //  cout<<x<<" ";
    if(x == Y && !b[x])
    {
        g<<s;
        b[x] = 1;
    }
    else
    {
        b[x] = 1;

        for(int i = 0; i < w[x].size(); i++)
        {
            if(b[w[x][i].first] == 0)
                parcurgere(w[x][i].first,s+w[x][i].second);
        }
    }
}
int main()
{
    int n,m,X;

    f>>n>>m>>X>>Y;

    w.resize(n+1);

    for(int i = 1; i <= m; i++)
    {
        int x, y, d;

        f>>x>>y>>d;

        w[x].push_back(make_pair(y, d));
        w[y].push_back(make_pair(x, -d));
    }
    parcurgere(X,0);
}
