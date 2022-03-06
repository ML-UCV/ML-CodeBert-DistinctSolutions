#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>


using namespace std;



ifstream fin ("dmin.in");

ofstream fout ("dmin.out");



const int MOD = 104659;

const double eps = 1e-10;

int n, m, S[1510];

double DM[1510];

vector < pair < int, double > > V[1510];

set < pair < double, int > > H;



inline double Modul(double x)

{

    if (x < 0) return -x;

    return x;

}



int main()

{

    fin >> n >> m;

    for (int x, y, c, i = 1; i <= m; i ++)

    {

        fin >> x >> y >> c;

        V[x].push_back( { y, log2(c) } );

        V[y].push_back( { x, log2(c) } );

    }



    memset(DM, 127, sizeof(DM));

    DM[1] = 0;

    S[1] = 1;

    H.insert( { 0, 1 } );

    while (!H.empty())

    {

        pair < double, int > aux = *H.begin();

        H.erase(H.begin());



        for (vector < pair < int, double > > :: iterator it = V[aux.second].begin(); it != V[aux.second].end(); it ++)

        {

            if (aux.first + it->second + eps < DM[it->first])

            {

                DM[it->first] = aux.first + it->second;

                H.insert( { DM[it->first], it->first } );

                S[it->first] = S[aux.second];

            }

            else if (Modul(aux.first + it->second - DM[it->first]) <= eps)

            {

                S[it->first] += S[aux.second];

                if (S[it->first] >= MOD) S[it->first] -= MOD;

            }

        }

    }



    for (int i = 2; i <= n; i ++) fout << S[i] << ' ';

    fout << '\n';

    fout.close();

    return 0;

}
