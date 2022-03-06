#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define Nmax 30005

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

vector < pair < int, int > > Numbers[Nmax];
queue < int > Coada;

int nod_start, nod_finish;
int Distanta[Nmax];

void BFS()
{
    Coada.push(nod_start);
    int Nod, Vecin;
    while (!Coada.empty())
    {
        Nod = Coada.front();
        Coada.pop();
        for (unsigned int i = 0; i < Numbers[Nod].size(); i++)
        {
            Vecin = Numbers[Nod][i].first;
            if (Distanta[Vecin] == 0)
            {
                Distanta[Vecin] = Distanta[Nod] + Numbers[Nod][i].second;
                Coada.push(Vecin);
            }
        }
    }
}

int main()
{
    int vf, muchii;
    fin >> vf >> muchii >> nod_start >> nod_finish;
    while (muchii)
    {
        int x, y, cost;
        fin >> x >> y >> cost;
        Numbers[x].push_back({ y, cost });
        Numbers[y].push_back({ x, -cost });
        muchii--;
    }
    for (int i = 1; i <= vf; i++)
        Distanta[i] = 0;
    BFS();
    fout << Distanta[nod_finish];
    return 0;
}
