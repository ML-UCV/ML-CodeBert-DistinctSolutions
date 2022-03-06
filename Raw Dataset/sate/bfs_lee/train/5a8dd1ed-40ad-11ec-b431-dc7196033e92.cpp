#include<fstream>
#include<vector>
#include<queue>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
int X, Y, n, m, a, b, c;
int f[30005];
vector< pair<int,int> > v[30005];
queue< pair<int, int> > q;
int main(){
    fin >> n >> m >> X >> Y;
    for( int i = 1; i <= m; i++ ){
        fin >> a >> b >> c;
        v[a].push_back( make_pair( b, c ) );
        v[b].push_back( make_pair( a, c ) );
    }
    q.push( make_pair( X, 0 ) );
    f[X] = 1;
    while( !q.empty() ){
        int nod = q.front().first;
        int D = q.front().second;
        for( int i = 0; i < v[nod].size(); i++ ){
            int vecin = v[nod][i].first;
            int cost = v[nod][i].second;
            if( f[vecin] == 0 ){
                if( vecin == Y ){
                    if( vecin > nod ){
                        fout << D + cost << "\n";
                    }else{
                        fout << D - cost << "\n";
                    }
                    return 0;
                }
                if( vecin > nod ){
                    q.push( make_pair( vecin, D + cost ) );
                }else{
                    if( vecin < nod ){
                        q.push( make_pair( vecin, D - cost ) );
                    }
                }
                f[vecin] = 1;
            }
        }
        q.pop();
    }
    return 0;
}
