#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;



ifstream f("dmin.in");

ofstream g("dmin.out");



bool Equal (double a, double b)

{

    return fabs(a-b)<1e-8;

}



typedef pair<int, double> PI;



struct CMP

{

    bool operator () (const PI& a, const PI& b) const

    {

        return a.second>b.second;

    }

};



priority_queue<PI, vector<PI>, CMP> Q;

int N, M;

vector <PI> G[1510];

double Dist[1510];

int DP[1510];



void Read ()

{

    f >> N >> M;

    for (int i=1; i<=M; i++)

    {

        int a, b, c;

        f >> a >> b >> c;

        G[a].push_back(make_pair(b, log(1.0*c)));

        G[b].push_back(make_pair(a, log(1.0*c)));

    }



    f.close();

}



void DoDijkstra ()

{

    vector<PI>::iterator it;

    int i, first;

    double second;



    for (i=1; i<=N; i++)

        Dist[i]=999999999;



    Dist[1]=0;

    DP[1]=1;

    Q.push(make_pair(1, 0));



    while (!Q.empty())

    {

        first=Q.top().first;

        second=Q.top().second;

        Q.pop();



        if (!Equal(Dist[first], second))

            continue;



        for (it=G[first].begin(); it!=G[first].end(); ++it)

            if (second+it->second<Dist[it->first] || Equal(second+it->second, Dist[it->first]))

            {

                if (second+it->second<=Dist[it->first]-1e-8)

                {

                    Dist[it->first]=second+it->second;

                    Q.push(make_pair(it->first, Dist[it->first]));

                    DP[it->first]=0;

                }

                DP[it->first]+=DP[first];

                if (DP[it->first]>=104659)

                    DP[it->first]-=104659;

            }

    }

}



void Print ()

{

    for (int i=2; i<=N; i++)

        g << DP[i] << ' ';

    g << '\n';



    g.close();

}



int main ()

{

    Read();

    DoDijkstra();

    Print();



    return 0;

}
