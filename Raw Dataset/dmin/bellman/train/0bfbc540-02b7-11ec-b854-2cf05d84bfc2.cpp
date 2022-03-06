#include <cmath>
#include <fstream>
#include <queue>
#include <vector>


using namespace std;



ifstream fin("dmin.in");

ofstream fout("dmin.out");



const double inf= 0x3f3f3f;

const double eps= 0.0000001;

const int nmax= 1500;

const int mod= 104659;



double minim[nmax+1];

int d[nmax+1];



struct str {

    int x;

    double y;

};



struct str_cmp {

    bool operator () ( const str &x, const str &y ) {

        return x.y>y.y;

    }

};



priority_queue <str, vector <str>, str_cmp> h;

vector <str> v[nmax+1];



inline str mp( int x, double y ) {

    str sol;

    sol.x= x, sol.y= y;



    return sol;

}



double av( double x ) {

    if ( x<0 ) {

        x= -x;

    }

    return x;

}



void dijkstra( ) {

    d[1]= 1;

    for ( h.push(mp(1, 0)); !h.empty(); ) {

        str x= h.top();

        h.pop();



        if ( x.y-minim[x.x]>=eps ) {

            continue;

        }



        for ( vector <str>::iterator it= v[x.x].begin(); it!=v[x.x].end(); ++it ) {

            if ( minim[(*it).x]-minim[x.x]-(*it).y>eps ) {

                minim[(*it).x]= minim[x.x]+(*it).y;

                d[(*it).x]= d[x.x];

                h.push(mp((*it).x, minim[(*it).x]));

            } else if ( av(minim[(*it).x]-minim[x.x]-(*it).y)<=eps ) {

                d[(*it).x]= (d[(*it).x]+d[x.x])%mod;

            }

        }

    }

}



int main( ) {

    int n, m;

    fin>>n>>m;

    for ( int i= 1; i<=m; ++i ) {

        int x, y;

        double z;

        fin>>x>>y>>z;

        z= log(z);



        v[x].push_back(mp(y, z));

        v[y].push_back(mp(x, z));

    }



    for ( int i= 2; i<=n; ++i ) {

        minim[i]= inf;

    }

    dijkstra();



    for ( int i= 2; i<=n; ++i ) {

        fout<<d[i]<<" ";

    }

    fout<<"\n";



    return 0;

}
