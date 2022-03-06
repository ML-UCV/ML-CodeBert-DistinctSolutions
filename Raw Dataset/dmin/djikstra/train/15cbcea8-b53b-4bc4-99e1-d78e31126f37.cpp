#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <cmath>
#include <set>
using namespace std;



typedef pair<int, double> per;

typedef vector<per>::iterator it;



int n,m,rez[1505];

double d[1505];

bitset<1505> viz;

vector<per> gr[1505];

set<pair<double, int> > s;



void dij() {

    for(int i=1; i<=n; ++i) d[i]=2000000000;

    rez[1]=1;

    for(s.insert(make_pair(0,1));s.size();s.erase(s.begin())) {

        double cst=s.begin()->first; int nod=s.begin()->second;

        for(it i=gr[nod].begin(); i!=gr[nod].end(); ++i) {

            if(fabs(d[i->first]-cst-i->second)<1e-9) rez[i->first]=(rez[i->first]+rez[nod])%104659;

            else if(cst+i->second<d[i->first]) {

                d[i->first]=cst+i->second;

                rez[i->first]=rez[nod];

                s.insert(make_pair(d[i->first],i->first));

            }

        }

    }

}



int main()

{

    ifstream f("dmin.in");

    ofstream g("dmin.out");

    f>>n>>m;

    for(int i=1; i<=m; ++i) {

        int a,b,c;

        f>>a>>b>>c;

        double lg=log((double)c);

        gr[a].push_back(make_pair(b,lg));

        gr[b].push_back(make_pair(a,lg));

    }

    dij();

    for(int i=2; i<=n; ++i) g<<rez[i]<<' ';

    return 0;

}
