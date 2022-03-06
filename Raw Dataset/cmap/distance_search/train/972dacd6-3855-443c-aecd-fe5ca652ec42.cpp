#include <bits/stdc++.h>


using namespace std;

ifstream fi("cmap.in");

ofstream fo("cmap.out");

int N;

pair <long long, long long> P[100001];

set <pair<long long,long long>> S;

long long dmin;

int lef;

int main()

{

    fi>>N;

    for (int i=1;i<=N;i++)

        fi>>P[i].first>>P[i].second;

    sort(P+1,P+N+1);

    dmin=(long long)2000000000*(long long)2000000000;

    S.insert({P[1].second,P[1].first});

    lef=1;

    for (int i=2;i<=N;i++)

    {



        while (lef<i && (long long)(P[i].first-P[lef].first)*(long long)(P[i].first-P[lef].first)>=dmin)

        {

            S.erase({P[lef].second,P[lef].first});

            lef++;

        }



        set <pair<long long,long long>> :: iterator it;

        it=S.lower_bound({P[i].second-dmin,P[i].first-dmin});

        int nr;

        nr=1;

        while ((it!=S.end()) && (nr<=5))

        {

            dmin=min(dmin,(long long)((*it).first-P[i].second)*(long long)((*it).first-P[i].second)+(long long)((*it).second-P[i].first)*(long long)((*it).second-P[i].first));

            it++;

            nr++;

        }

        S.insert({P[i].second,P[i].first});

    }

    fo<<setprecision(7)<<fixed<<sqrtl((long double)dmin);

    fi.close();

    fo.close();

    return 0;

}
