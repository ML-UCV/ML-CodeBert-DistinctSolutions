#include <fstream>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

ifstream fi("dmin.in");

ofstream fo("dmin.out");

int n,m;

vector<pair<int,int> > V[1501];

set<pair<int,int> > S;

long double D[1501];

int P[1501];

void dijkstra()

{

    S.insert(make_pair(D[1],1));

    while(!S.empty())

    {

        pair<int,int>aux=(*S.begin());

        int nod=aux.second;

        S.erase(S.begin());

        for(auto it:V[nod])

        {

            int to=it.first;

            long double cost=log10(it.second);

            if(abs(D[nod]+cost-D[to])<=0.00000001)

                P[to]=(P[to]+P[nod])%104659;

            else if(D[nod]+cost<D[to]+0.00000001)

            {

                if(abs(D[to]-100000000.0)>0.00000001)

                    S.erase(S.find(make_pair(D[to],to)));

                D[to]=D[nod]+cost;

                P[to]=P[nod]%104659;

                S.insert(make_pair(D[to],to));

            }

        }

    }

}

int main()

{

    fi>>n>>m;

    for(int i=1;i<=m;i++)

    {

        int a,b,c;

        fi>>a>>b>>c;

        V[a].push_back(make_pair(b,c));

        V[b].push_back(make_pair(a,c));

    }

    for(int i=1;i<=n;i++)

        D[i]=100000000.0;

    D[1]=0,P[1]=1;

    dijkstra();

    for(int i=2;i<=n;i++)

        fo<<P[i]<<" ";

    fi.close();

    fo.close();

    return 0;

}
