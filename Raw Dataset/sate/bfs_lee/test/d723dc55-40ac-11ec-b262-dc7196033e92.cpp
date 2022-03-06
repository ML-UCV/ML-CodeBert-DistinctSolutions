#include <fstream>
#include <queue>
using namespace std;
 
ifstream fin("sate.in");
ofstream fout("sate.out");
 
int a[30001];
//a[i] = distanta de la nodul x la nodul i; arata si daca am trecut prin nodul i deja, ca daca nu am trecut am valoarea 0
 
struct nod
{
    int v, d;
    struct nod *urm;
};
 
void pune(nod *&prim, int v, int d)
{
    nod *q = new nod;
    q->v = v;
    q->d = d;
    q->urm = prim;
    prim = q;
}
 
nod *v[30001] = {};
 
queue <int> q;
 
int bfs(int s, int f)
{
    //s = start; f = finis, final.
    int na, nv;
    nod *i = new nod;
    //na = nod curent, nv = nod "vecin"
    a[s] = 1;
    q.push(s);
    while (1)
    {
        na = q.front();
        q.pop();
        for (i = v[na]; i!=NULL; i=i->urm)
        {
            nv = i->v;
            if (a[nv] == 0)
            {
                a[nv] = a[na] + i->d;
                if (nv == f)
                    return a[f];
                q.push(nv);
            }
        }
    }
    return -1;
}
 
int main()
{
    int n, m, i, x, y, eins, zwei, d;
    fin >> n >> m >> x >> y;
    for (i = 1; i<=m; i++)
    {
        fin >> eins >> zwei >> d;
        pune(v[eins], zwei, d);
        pune(v[zwei], eins, -d);
    }
    fout << bfs(x, y) - 1;
    return 0;
}
