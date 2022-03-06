#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int n, m, nr[1503];

double dmin[1503];

vector <pair<double, int> > v[1503];

bool use[1503];



class compare

{

public:

    bool operator()(const int &a, const int &b)

    {

        if(dmin[a]>dmin[b])

            return true;

        return false;

    }

};



priority_queue <int, vector<int>, compare> q;





void read()

{

    freopen("dmin.in", "r", stdin);

    freopen("dmin.out", "w", stdout);

    int a, b, c;

    double cc;

    scanf("%i %i", &n, &m);

    for(int i=1; i<=m; i++)

    {

        scanf("%i %i %i", &a, &b, &c);

        cc=log(c);

        v[a].push_back(make_pair(cc,b));

        v[b].push_back(make_pair(cc,a));

    }



}



void dijkstra()

{

    for(int i=2; i<=n; i++)

        dmin[i]=1<<30;



    q.push(1);

    nr[1]=1;

    int first;

    while(!q.empty())

    {



        first=q.top();

        q.pop();

        if(use[first])

            continue;

        use[first]=1;

        for(int i=0; i<v[first].size(); ++i)

        {

            pair<double, int> k=v[first][i];



                if( fabs(dmin[k.second]-dmin[first]-k.first) < 1e-9 )

                {

                    nr[k.second]+=nr[first];

                    if(nr[k.second]>104659) nr[k.second]-=104659;

                }

                else if(dmin[k.second]>dmin[first]+k.first)

                {

                    nr[k.second]=nr[first];

                    if(nr[k.second]>104659) nr[k.second]-=104659;

                    dmin[k.second]=dmin[first]+k.first;

                    q.push(k.second);

                }





        }

    }



}



int main()

{

    read();

    dijkstra();



    for(int i=2; i<=n; i++)

        printf("%i ", nr[i]);

    printf("\n");

    return 0;

}
