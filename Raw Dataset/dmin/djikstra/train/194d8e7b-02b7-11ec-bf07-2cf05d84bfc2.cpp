#include <fstream>
#include <set>
#include <vector>
#include <cmath>
typedef std :: pair < int, double > NOD;



std :: ifstream f("dmin.in");

std :: ofstream g("dmin.out");



int N, M, Count[1509];

double D[1509];



std :: vector < NOD > V[1509];

std :: set < NOD > H;



inline void Read_Data() {

    f >> N >> M;



    double cost;

    for(int i = 1, x, y; i <= M; ++i) {

        f >> x >> y >> cost;

        cost = log(cost);

        V[x].push_back(std :: make_pair(y, cost));

        V[y].push_back(std :: make_pair(x, cost));

    }

}



inline double modul(double a) {

    if(a < 0) a *= -1.0;

    return a;

}



void Djikstra() {

    H.insert( {1, 0} );



    while(!H.empty()) {

        NOD nod = *H.begin();

        H.erase( *H.begin() );



        for(auto val : V[nod.first])

            if(D[val.first] - val.second - nod.second > 1e-10) {

                Count[val.first] = Count[nod.first] % 104659;

                H.erase( {val.first, D[val.first]} );



                D[val.first] = nod.second + val.second;

                H.insert( {val.first, D[val.first]} );

            } else if(modul(D[val.first] - nod.second - val.second) < 1e-10)

                        Count[val.first] = (Count[val.first] + Count[nod.first] ) % 104659;



    }

}



int main() {

    Read_Data();



    for(int i = 2; i <= N; ++i) D[i] = (1 << 30);

    Count[1] = 1;

    Djikstra();



    for(int i = 2; i <= N; ++i) g << Count[i] << ' ';



    g.close();

    return 0;

}
