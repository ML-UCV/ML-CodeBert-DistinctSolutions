#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");

const int NMAX = 100024;

int distanta[NMAX];
int Coada[NMAX], N, M, X, Y;
vector<pair<int, int> > A[NMAX];
bool viz[NMAX];

void citire()
{
    f >> N >> M >> X >> Y;
    for(int i = 1; i <= M; i++)
    {
        int a, b, d;
        f >> a >> b >> d;
        A[a].push_back(make_pair(b, d));
        A[b].push_back(make_pair(a, d));
    }
}

void BFS()
{
    int st = 0, dr = 0;

    viz[X] = 1;
    Coada[0] = X;         ///adaugam nodul in coada

    while(st <= dr)       ///parcurgem graful
    {
        int x = Coada[st++];   ///extragem primul element din coada
        for(int i = 0; i < A[x].size(); i++)          ///parcurgem vectorul de arce al nodului curent (x)
        {
            int vecin_curent = A[x][i].first;
            int D = A[x][i].second;
            if(viz[vecin_curent] == 0)
            {
                viz[vecin_curent] = 1;
                if(x < vecin_curent)                   ///daca elementul din coada e mai mic decat nodul curent adaugam distanta, altfel o scadem
                    distanta[vecin_curent]=distanta[x] + D;
                else
                    distanta[vecin_curent]=distanta[x] - D;

                Coada[++dr] = vecin_curent;              ///adaugam noul nod gasit in coada
            }
        }
    }
}

int main()
{
    citire();
    //
    BFS();
    //
    g << distanta[Y] << ' ';
    return 0;
}
