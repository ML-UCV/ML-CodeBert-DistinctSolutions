#include<fstream>
#include<vector>
#include<cmath>
#include<queue>






using namespace std;

ifstream fin("dmin.in");

ofstream fout("dmin.out");

int n, m, a, b, c;

vector< pair<int, double> > v[1505];

double d[1505];

int cnt[1505];

priority_queue< pair< double, int >, vector< pair< double, int > >, greater< pair< double, int > > > q;



double modul( double x ){

    if( x > 0 ){

        return x;

    }

    return -x;

}



int main(){

    fin >> n >> m;

    for( int i = 1; i <= m; i++ ){

        fin >> a >> b >> c;

        v[a].push_back( make_pair( b, log(c) ) );

        v[b].push_back( make_pair( a, log(c) ) );

    }

    for( int i = 2; i <= n; i++ ){

        d[i] = 20000000000.0;

    }

    cnt[1] = 1;

    q.push( make_pair( 0, 1 ) );

    while( !q.empty() ){

        int nod = q.top().second;



        if( q.top().first - d[nod] >= 0.0000000001 ){

            q.pop();

            continue;

        }



        for( int i = 0; i < v[nod].size(); i++ ){

            int vecin = v[nod][i].first;

            double cost = v[nod][i].second + d[nod];

            if( modul( d[vecin] - cost ) <= 0.0000000001 ){

                cnt[vecin] = ( cnt[vecin] + cnt[nod] ) % 104659;

            }else{

                if( cost < d[vecin] ){

                    d[vecin] = cost;

                    cnt[vecin] = cnt[nod];

                    q.push( make_pair( d[vecin], vecin ) );

                }

            }

        }



        q.pop();

    }

    for( int i = 2; i <= n; i++ ){

        fout << cnt[i] << " ";

    }

    return 0;

}
