#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;



ifstream f("dmin.in");

ofstream g("dmin.out");



double EPS=1e-8;

double d[1505];

int cnt[1505];

bool in[1505];

struct cmp{

    bool operator()(int x, int y)

    {

        return d[x]-d[y]>EPS;

    }

};



int n, m;

vector <pair <int, long double> > v[1505];

priority_queue <int, vector <int>, cmp> Q;



void dijkstra()

{

    for (int i = 2; i <= n; i++)

        d[i]=0x3f3f3f3f;



    cnt[1]=1;

    d[1]=0;

    in[1]=1;

    Q.push(1);

    while(!Q.empty())

    {

        int x=Q.top();

        in[x]=0;

        Q.pop();

        for (int i = 0; i < v[x].size(); i++)

        {

            int y=v[x][i].first;

            double c=v[x][i].second;

            if(d[y]-d[x]-c>EPS)

            {

                cnt[y]=cnt[x]%104659;

                d[y]=d[x]+c;

                if(in[y] == 0)

                {

                    Q.push(y);

                    in[y]=1;

                }

            }

            else

            {

                if(abs(d[y]-d[x]-c)<EPS)

                {

                    cnt[y]+=cnt[x];

                    cnt[y]%=104659;

                }

            }

        }

    }



    for (int i = 2; i <= n; i++) g << cnt[i] << " " ;



}



int main()

{

    f >> n >> m;

    for (int i = 1; i <= m; i++)

    {

        int x, y;

        long double c;

        f >> x >> y >> c;

        v[x].push_back({y, log2(1.0*c)});

        v[y].push_back({x, log2(1.0*c)});

    }



    dijkstra();



    return 0;

}
