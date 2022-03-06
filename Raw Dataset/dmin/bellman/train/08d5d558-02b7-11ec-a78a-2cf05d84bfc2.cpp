#include <fstream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

ifstream f("dmin.in");

ofstream g("dmin.out");
struct Muchie{

    int vecin;

    double cost;

};



queue <int> Q;

vector <Muchie> A[1501];

int n, m, nrd[1501], inq[1501];

double dmin[1501];



int main()

{

    int a, b, i;

    double c;

    Muchie T;





    f>>n>>m;

    for(i = 1; i <= m; i++) {

        f>>a>>b>>c;

        c = log(c);

        T.vecin = b; T.cost = c;

        A[a].push_back(T);

        T.vecin = a; T.cost = c;

        A[b].push_back(T);

    }





    dmin[1] = 0;

    for(i = 2; i <= n; i++) dmin[i] = 1000000001;

    nrd[1] = 1;

    for(i = 2; i <= n; i++) nrd[i] = 0;





    Q.push(1); inq[1] = 1;

    while(!Q.empty()) {

        int x = Q.front(); Q.pop(); inq[x] = 0;

        for(i = 0; i < A[x].size(); i++) {

            int vecin = A[x][i].vecin;

            double cost = A[x][i].cost;

            double dif = dmin[vecin] - dmin[x] - cost;

            if(dif < 0) dif = -dif;

            if(dif < 0.0000000001)

                nrd[vecin] = (nrd[vecin] + nrd[x]) % 104659;

            else

                if(dmin[vecin] > dmin[x] + cost) {

                    dmin[vecin] = dmin[x] + cost;

                    nrd[vecin] = nrd[x];

                    if(!inq[vecin]) {

                        Q.push(vecin);

                        inq[vecin] = 1;

                    }

                }

        }

    }



    for(i = 2; i <= n; i++) g<<nrd[i]<<' ';

    g<<'\n';



    return 0;

}
