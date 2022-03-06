#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
using namespace std;



typedef vector<pair<int,double> >::iterator it;



vector<pair<int,double> > gf[1501];

int rez[1501], n, m;

double d[1501];

set <pair<double,int> > h;



void dijkstra(){

    for (int i=1; i<=n; i++) d[i] = 987654321;

    rez[1]=1;

    for(h.insert(make_pair(0,1)); h.size(); h.erase(h.begin())){

        double min = h.begin()->first;

        int nod = h.begin()->second;

        for(it i=gf[nod].begin(); i!=gf[nod].end(); i++){

            int vecin = i->first;

            double cost = i->second;

            if ( fabs(d[vecin] - min - cost ) < 1e-9 ) rez[vecin] = (rez[vecin] + rez[nod]) % 104659;

            else if(d[vecin] > min + cost){

                d[vecin] = min + cost;

                rez[vecin] = rez[nod];

                h.insert(make_pair(d[vecin], vecin));

            }

        }

    }

}



int main(){

    ifstream f("dmin.in");

    ofstream g("dmin.out");

    f>>n>>m;

    for(int i=1; i<=m; i++){

        int first, second, c;

        f>>first>>second>>c;

        gf[first].push_back(make_pair(second,log(c)));

        gf[second].push_back(make_pair(first,log(c)));

    }



    dijkstra();

    for(int i=2; i<=n; i++) g<<rez[i]<<" ";

    return 0;

}
