#include <fstream>
#include <queue>
#include <vector>
#define NMAX 30010

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int n, x, y, m, dist[NMAX];
//vector < pair <int,int> > v[NMAX];
struct nodd
{
    int first, second;
    nodd *urm;
};
nodd *v[NMAX];
void add(nodd *&p, int x, int y)
{
    if(p == NULL)
    {
        p = new nodd;
        p ->first = x;
        p ->second = y;
        p ->urm = NULL;
    }
    else
    {
        nodd *nou = new nodd;
        nou ->first = x;
        nou ->second = y;
        nou -> urm = p;
        p = nou;
    }
}

int BFS(int start, int finish)
{
    nodd *Q, *uQ;
    if(start == finish) return 0;
    Q = new nodd;
    Q ->first = start;
    Q ->urm = NULL;
    uQ = Q;
    while(Q != NULL && !dist[finish])
    {
        int nod = Q ->first;
        for(nodd *i = v[nod]; i != NULL; i = i ->urm)
        if(dist[i ->first] == 0 && (i ->first != start) )
        {
            dist[i ->first] = dist[nod] + i ->second;
            nodd *now = new nodd;
            now ->first = i ->first;
            now ->urm = NULL;
            uQ ->urm = now;
            uQ = now;
        }
        Q = Q->urm;
    }
    return dist[finish];
}
int main()
{
    f >> n >> m >> x >> y;

    for(int i = 1; i <= m; ++i)
    {
        int a, b, cost;
        f >> a >> b >> cost;
        add(v[a],b,cost);
        add(v[b],a,-cost);
       //   v[a].push_back({b,cost});
       //   v[b].push_back({a,-cost});
    }
    g << BFS(x,y);
    f.close(); g.close();
    return 0;
}
