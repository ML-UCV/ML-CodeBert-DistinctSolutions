#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

int n, m, i, x, y, nod, vecin, cost, j;

int viz[1505], num[1505], h[1505], poz[1505];

double d[1505], cost2;

vector< pair<int, double> > v[1505];

ifstream fin("dmin.in");

ofstream fout("dmin.out");

double modul(double x){

    if(x > 0){

        return x;

    }

    return -x;

}

void upd(int pos){

    int c = pos, p = c / 2;

    while(p > 0 && d[ h[p] ] > d[ h[c] ]){

        swap(h[p], h[c]);

        poz[ h[p] ] = p;

        poz[ h[c] ] = c;

        c = p;

        p = c / 2;

    }

}

void elim(){

    int p = 1, c = 2;

    while(c <= n){

        if(c + 1 <= n && d[ h[c] ] > d[ h[c + 1] ]){

            c++;

        }

        if(d[ h[p] ] > d[ h[c] ]){

            swap(h[p], h[c]);

            poz[ h[p] ] = p;

            poz[ h[c] ] = c;

            p = c;

            c = 2 * p;

        }

        else{

            break;

        }

    }

}

int main(){

    fin>> n >> m;

    for(i = 1; i <= m; i++){

        fin>> x >> y >> cost;

        cost2 = log(cost);

        v[x].push_back( make_pair(y, cost2) );

        v[y].push_back( make_pair(x, cost2) );

    }

    for(i = 1; i <= n; i++){

        d[i] = 1000000000;

        h[i] = poz[i] = i;

    }

    d[1] = 0;

    num[1] = 1;

    for(i = 1; i <= n; i++){

        nod = h[1];

        for(j = 0; j < v[nod].size(); j++){

            vecin = v[nod][j].first;

            if(viz[vecin] == 0){

                if(modul(d[vecin] - d[nod] - v[nod][j].second) <= 0.000000001){

                    num[vecin] += num[nod];

                    if(num[vecin] >= 104659){

                        num[vecin] -= 104659;

                    }

                }

                else{

                    if(d[nod] + v[nod][j].second < d[vecin]){

                        d[vecin] = d[nod] + v[nod][j].second;

                        upd(poz[vecin]);

                        num[vecin] = num[nod];

                    }

                }

            }

        }

        viz[nod] = 1;

        d[nod] = 1000000000;

        elim();

    }

    for(i = 2; i <= n; i++){

        fout<< num[i] <<" ";

    }

    return 0;

}
