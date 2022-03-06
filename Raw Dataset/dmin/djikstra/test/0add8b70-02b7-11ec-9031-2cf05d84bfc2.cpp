#include <fstream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;



ifstream fin("dmin.in");

ofstream fout("dmin.out");



int n, m, in[1510], nrd[1510];

double D[1510];



vector<int> A[1510];

vector<double> C[1510];

queue<int> Q;





int main()

{

    int i, a, b, nod, vecin;

    double c, cost;

    fin >> n >> m;

    for (i = 1; i <= m; i++)

    {

        fin >> a >> b >> c;

        A[a].push_back(b);

        C[a].push_back(log10(c));

        A[b].push_back(a);

        C[b].push_back(log10(c));

    }

    for (i = 2; i <= n; i++)

        D[i] = 1000000000;

    nrd[1] = 1;

    Q.push(1);

    in[1] = 1;

    while (!Q.empty())

    {

        nod = Q.front();

        Q.pop();

        in[nod] = 0;

        for (i = 0; i < A[nod].size(); i++)

        {

            vecin = A[nod][i];

            cost = C[nod][i];

            if (D[vecin] > D[nod] + cost + 0.0000000001)

            {

                D[vecin] = D[nod] + cost;

                nrd[vecin] = nrd[nod] % 104659;

                if (!in[vecin])

                {

                    in[vecin] = 1;

                    Q.push(vecin);

                }

            }

            else if (abs(D[vecin] - D[nod] - cost) < 0.0000000001)

                nrd[vecin] = (nrd[vecin] % 104659 + nrd[nod] % 104659) % 104659;

        }

    }

    for (i = 2; i <= n; i++)

        fout << nrd[i] << ' ';

    fout << '\n';

    fout.close();

    return 0;

}
