#include <iostream>
#include <vector>
#include <fstream>
#define Nmax 30005

using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");

vector<pair <int, int> >lista[Nmax];
int viz[Nmax];
int sol[Nmax];
int n,m;
int X,Y;

void citire()
{
    int x,y,z,zprim;

    fin>>n>>m>>X>>Y;

    while(m--)
    {
        fin>>x>>y>>z;
        zprim=z*-1;

        lista[x].push_back(make_pair(y,z));
        lista[y].push_back(make_pair(x,zprim));

    }

    fin.close();
}


void DFS(int a)
{   viz[a]=1;
 if(!sol[Y])
    for(int i=0;i<lista[a].size();++i)
    {
        int satul_vecin=lista[a][i].first;
        int km=lista[a][i].second;

        if(!viz[satul_vecin])
    {
    sol[satul_vecin]=sol[a]+km;
            DFS(satul_vecin);
    }
}
}

int main()
{
    citire();
    DFS(X);
    fout<<sol[Y];
    return 0;
}
