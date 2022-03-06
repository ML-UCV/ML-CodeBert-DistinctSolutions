#include <fstream>
#include <cmath>
#include <queue>
using namespace std;



ifstream fin("dmin.in");

ofstream fout("dmin.out");



int n, m, nrd[1501];

double M[1501][1501], dmin[1501];

bool inq[1501];



queue<int> Q;



void citire()

{

    int a, b, t;

    fin >> n >> m;

    for(int i = 1; i <= n; i++)

        for(int j = 1; j <= n; j++)

            if(i != j) M[i][j] = 2000000000;

    while(m--)

        fin >> a >> b >> t, M[a][b] = M[b][a] = log(t);

}



void bellman_ford(int nod)

{

    Q.push(nod);

    inq[nod] = 1;

    for(int i = 1; i <= n; ++i) dmin[i] = 2000000000;

    dmin[1] = 0;

    nrd[1] = 1;

    while(!Q.empty())

    {

        int x = Q.front();

        Q.pop(); inq[x] = 0;

        for(int i = 1; i <= n; ++i){

            if(x != i)

                if(M[x][i] != 2000000000 && dmin[i] > dmin[x] + M[x][i] + 0.0000000001){

                    dmin[i] = dmin[x] + M[x][i];

                    nrd[i] = nrd[x];

                    if(inq[i] == 0) Q.push(i), inq[i] = 1;

                }

                else if(fabs(dmin[i] - dmin[x] - M[x][i]) < 0.0000000001 && M[x][i] != 2000000000) nrd[i] = (nrd[i] % 104659 + nrd[x] % 104659) % 104659;

        }

    }

}



int main()

{

    citire();

    bellman_ford(1);

    for(int i = 2; i <= n; i++)

        fout << nrd[i] << ' ';

    return 0;

}
