#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

ifstream in("ctc.in");
ofstream out("ctc.out");

const int dim = 200005;

int n,nr1 = 0,nr2 = 0,urm1[dim],urm2[dim],lst1[dim],lst2[dim],vf1[dim],vf2[dim],m,viz[dim],q[dim],st;
vector <int> componente[dim];
int cnt;

void Adauga1(int x,int y)
{
    vf1[++nr1] = y;
    urm1[nr1] = lst1[x];
    lst1[x] = nr1;
}

void Adauga2(int x,int y)
{
    vf2[++nr2] = y;
    urm2[nr2] = lst2[x];
    lst2[x] = nr2;
}

void DFS1(int nod)
{
    viz[nod] = 1;

    for (int p= lst1[nod]; p!=0; p = urm1[p])
    {
        int y = vf1[p];
        if (!viz[y])
        {
            DFS1(y);
        }
    }
    q[++st] = nod;
}

void DFS2(int nod)
{
    componente[cnt].push_back(nod);
    viz[nod] = 1;

    for (int p= lst2[nod]; p!=0; p = urm2[p])
    {
        int y = vf2[p];
        if (!viz[y])
        {
            DFS2(y);
        }
    }
}

int main()
{
    in >> n >> m;
    for (int i=1,x,y; i<=m; i++)
    {
        in >> x >> y;
        Adauga1(x,y);
        Adauga2(y,x);
    }

    for (int i=1; i<=n; i++)
    {
        if (!viz[i])
        {
           DFS1(i);
        }
    }
    memset(viz,0,sizeof(viz));

    for (int i=st; i>=1; i--)
    {
       if (!viz[q[i]])
       {
          cnt++;
          DFS2(q[i]);
       }
    }

    out << cnt << "\n";

    for (int i=1; i<=cnt; i++)
    {
        for (auto j:componente[i])
        {
            out << j << " ";
        }
        out << "\n";
    }
    return 0;
}
