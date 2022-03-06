#include <bits/stdc++.h>


using namespace std;

typedef pair <long long, long long> pairll;

ifstream fi("cmap.in");

ofstream fo("cmap.out");

int N;

pairll P[100001];

int lef;

set <pairll> S;

long double dmin;



int cmp(pairll a, pairll b)

{

    if (a.second<b.second)

        return 1;

    if (a.second>b.second)

        return 0;

    return a.first<b.first;

}



long double distanta(pairll a, pairll b)

{

    return sqrtl((long double)((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second)));

}



int main()

{

    fi>>N;

    for (int i=1;i<=N;i++)

        fi>>P[i].second>>P[i].first;

    sort(P+1,P+N+1,cmp);



    lef=1;

    S.insert(P[1]);

    dmin=(long double)1e10;

    for (int i=2;i<=N;i++)

    {



        while (lef<i && P[i].second-P[lef].second>dmin)

        {

            S.erase(P[lef]);

            lef++;

        }



        set <pairll> :: iterator it;

        it=S.lower_bound({(long long)(P[i].first-dmin),(long long)(P[i].second-dmin)});

        int nr;

        nr=1;

        while (it!=S.end() && nr<=5)

        {

            dmin=min(dmin,distanta(P[i],*it));

            it++;

            nr++;

        }

        S.insert(P[i]);

    }

    fo<<setprecision(7)<<fixed<<dmin;

    fi.close();

    fo.close();

    return 0;

}
