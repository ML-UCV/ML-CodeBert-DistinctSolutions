#include <fstream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

ifstream is("dmin.in");
ofstream os("dmin.out");




int N, M, x, y;
double D[1503], z;
int Nr[1503];
vector <pair<int,double> > G[1503];



struct Comp

{

    bool operator() (const pair<int, double> X, const pair<int, double> &Y) const

    {

        return X.second > Y.second;

    }

};
priority_queue <pair<int,double>, vector<pair<int,double> >, Comp > P;

void Input();
void Dijkstra();

int main()
{
    Input();
    Dijkstra();

    for ( int i = 2; i <= N; ++i )
        os << Nr[i] << " ";
    is.close();
    os.close();
}

void Input()
{
    is >> N >> M;
    for ( int i = 1; i <= M; ++i )
    {
        is >> x >> y >> z;
        G[x].push_back(make_pair(y,log10(z)));

        G[y].push_back(make_pair(x,log10(z)));
    }
    for ( int i = 1; i <= N; ++i )
        D[i] = 1<<30;
    D[1] = 0;
    Nr[1] = 1;
}

void Dijkstra()
{
    P.push(make_pair(1,0));
    vector <pair<int,double> > :: iterator it;
    int nd;

    double cs;
    while ( !P.empty() )
    {
        nd = P.top().first;

        cs = P.top().second;
        P.pop();


        for ( it = G[nd].begin(); it != G[nd].end(); ++it )
        {
            if ( it->second + cs <= D[it->first] - 1e-8 )
            {
                D[it->first] = it->second + cs;
                Nr[it->first] = Nr[nd];
                P.push(make_pair(it->first,D[it->first]));
                Nr[it->first] %= 104659;

            }
            else if ( fabs(((it->second+cs)-(D[it->first]))) <= 1e-8 )
            {

                Nr[it->first] += Nr[nd];

                Nr[it->first] %= 104659;

            }
        }
    }
}
