#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
using namespace std;



ifstream fin("party.in");

ofstream fout("party.out");



vector<pair<int, int> >expr;

int n, m, p;

int sol[128];



void citire() {

    fin >> n >> m;

    for(int i = 1; i <= m; i++) {

        int x, y, z;

        fin >> x >> y>> z;

        if(z == 0)

            expr.push_back({x, y});

        else if (z == 1)

            expr.push_back({x, -y});

        else if (z == 2)

            expr.push_back({-x, y});

        else if (z == 3)

            expr.push_back({-x, -y});

    }

}



bool eval(pair<int, int> p) {

    int x = p.first;

    int y = p.second;



    return ( (x > 0 ? sol[abs(x)] : !sol[abs(x)]) | (y > 0 ? sol[abs(y)] : !sol[abs(y)]) );

}



void afis() {

    int nr = 0;

    for(int i = 1; i <= n; i++)

        if(sol[i])

            nr++;

    fout << nr << '\n';

    for(int i = 1; i <= n; i++)

        if(sol[i])

            fout << i << '\n';

}



void solve() {

    srand(time(0));

    for(int i = 1; i <= n; i++)

        sol[i] = rand()%2;



    while(true) {

        bool currRes = 1;

        for(int i = 0; i < expr.size(); i++) {

            currRes &= eval(expr[i]);

            if(!currRes) {

                p = i;

                break;

            }

        }



        if(currRes) {

            afis();

            return;

        }



        if(rand()%2)

            sol[abs(expr[p].first)] ^= 1;

        else

            sol[abs(expr[p].second)] ^= 1;

    }

}



int main() {

    citire();

    solve();

}
