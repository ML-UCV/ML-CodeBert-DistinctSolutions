#include <fstream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

ifstream f("dmin.in");

ofstream g("dmin.out");
struct comp

{

    bool operator()(pair<pair<int,int>,long double> i1 ,pair<pair<int,int>,long double> i2 )

    {

        return i1.second<i2.second;;

    }

};

multiset < pair<pair<int,int>,long double>,comp> Heap;



vector<pair<int,long double> > H[1666];

int n,m,i,xx,yy,j,cost;

int pos[1666];

long double dp[1666];

bool viz[1666];



long double mdl(long double value)

{

    if (value<0)

        return -value;

    else

        return value;

}



bool equal(long double AA,long double BB)

{

    if (mdl(AA-BB)<=0.0000000001)

        return true;



    return false;

}



int main()

{

    f>>n>>m;



    for(i=1; i<=m; ++i)

    {

        f>>xx>>yy>>cost;

        long double cost2=log10((long double)cost);

        H[xx].push_back(make_pair(yy,cost2));

        H[yy].push_back(make_pair(xx,cost2));

    }



    pos[1]=1;

    Heap.insert(make_pair(make_pair(1,1),0));



    while (Heap.empty()==false)

    {

        pair<pair<int,int>,long double> next=*(Heap.begin());

        Heap.erase(Heap.begin());



        if(next.first.second!=1)

            if (equal(dp[(next.first).second],next.second)==true||viz[next.first.second]==false)

            {

                pos[(next.first).second]+=pos[(next.first).first];

                pos[(next.first).second]%=104659;

            }

        if (viz[next.first.second]==true)

            continue;



        viz[next.first.second]=true;

        dp[next.first.second]=next.second;



        int N=H[next.first.second].size();



        for( i=0; i<N; ++i)

            Heap.insert(make_pair( make_pair(next.first.second,H[next.first.second][i].first),next.second+H[next.first.second][i].second ));

    }



    for(i=2; i<=n; ++i)

        g<<pos[i]<<" ";



    g<<'\n';



    f.close();

    g.close();

    return 0;

}
