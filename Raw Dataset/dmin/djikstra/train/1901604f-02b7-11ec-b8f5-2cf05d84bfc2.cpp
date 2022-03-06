#include <fstream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
const char IN[] = "dmin.in";

const char OUT[] = "dmin.out";

const int MAX = 1514;

const int MOD = 104659;

const int INF = 1<<30;



using namespace std;



ifstream fin(IN);

ofstream fout(OUT);



typedef std:: pair<int,double> P;

vector <P> gr[MAX];

struct cmp{

    bool operator()(const P &a,const P &b){

        return ( a.second>b.second );

    }

};

priority_queue <P,vector<P>,cmp> h;



double d[MAX];

int fr[MAX],n;

void dijkstra( );

int main( )

{

    int m;

    fin >> n >> m;

    while(m--){

        int x,y;

        double c,tr;

        fin >> x >> y >> c;

        tr=log10(c);

        gr[x].push_back( make_pair( y , tr ) );

        gr[y].push_back( make_pair ( x , tr ) );

    }

    for(register int i=2;i<=n;++i)d[i]=INF;

    dijkstra();

    for(int i=2; i<=n; i++)

        fout<<fr[i]<<' ';

    return 0;

}

void dijkstra( )

{

    h.push(make_pair(1,0));

    d[1]=0;

    fr[1]=1;

    while(!h.empty()){

        int fata=h.top().first;

        double cost=h.top().second;

        h.pop();

        for(register int i=0;i<(int)gr[fata].size();++i)

            if(abs(cost + gr[fata][i].second - d[gr[fata][i].first])<=0.0000000001){

                fr[gr[fata][i].first] += fr[fata];

                fr[gr[fata][i].first] %= MOD;

            }

            else if(cost + gr[fata][i].second < d[gr[fata][i].first])

            {

                d[gr[fata][i].first] = cost + gr[fata][i].second;

                fr[gr[fata][i].first] = fr[fata]%MOD;

                h.push(make_pair(gr[fata][i].first,d[gr[fata][i].first]));

            }

    }

}
