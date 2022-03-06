#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
using namespace std;



typedef vector<pair<int, double> >::iterator it;



int rez[1501], n, m;

double d[1501];

vector<pair<int, double> > gf[1501];

set<pair<double,int> > heap;



void dijkstra(){

    for(int i=0;i<=n;i++) d[i]=987654321;

    rez[1]=1;

    for(heap.insert(make_pair(0,1)); heap.size(); heap.erase(heap.begin())){

        double min = (heap.begin())->first;

        int nod = (heap.begin())->second;

        for(it i=gf[nod].begin(); i!=gf[nod].end(); i++){

            int vecin = i->first;

            double cost = i->second;

            if (fabs(d[i->first]-min-i->second)<1e-9)rez[i->first]= (rez[i->first] + rez[nod]) %104659;

            else if (min + i->second<d[i->first]){

                d[i->first] = min + i->second;

                rez[i->first] = rez[nod];

                heap.insert(make_pair(d[i->first], i->first));

            }

        }

    }

}



int main(){

    ifstream f("dmin.in");

    ofstream g("dmin.out");

    f>>n>>m;

    for(int i=1;i<=m;++i){

        int first,second,c;

        f>>first>>second>>c;

        double lg=log((double)c);

        gf[first].push_back(make_pair(second,lg));

        gf[second].push_back(make_pair(first,lg));

    }



    dijkstra();

    for(int i=2; i<=n; i++)

    g<<rez[i]<<" ";

    return 0;

}
