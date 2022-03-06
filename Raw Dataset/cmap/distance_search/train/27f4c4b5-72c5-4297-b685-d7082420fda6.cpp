#include <bits/stdc++.h>
using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

typedef pair<int,int> punct;

vector<punct> X;

set<punct> Y;

punct rot(punct);

double dist(punct,punct),d;

const int oo = 2000000000;

int n,j;

int main()

{

    f>>n;

    for(int i=1;i<=n;i++)

    {

        int x,y;

        f>>x>>y;

        X.push_back(make_pair(x,y));

    }

    sort(X.begin(),X.end());

    Y.insert(rot(X[0]));

    Y.insert(rot(X[1]));

    d=dist(X[0],X[1]);

    for(int i=2;i<n;i++)

    {

        while(X[j].first<=X[i].first-d)

        {

            Y.erase(rot(X[j]));

            j++;



        }

        punct P=rot(X[i]);

        set<punct>::iterator it=Y.lower_bound(make_pair(P.first-int(d)-1,-oo));

        while(it!=Y.end()&&1.0*(it->first-P.first)<d)

        {

            d=min(d,dist(P,*it));

            it++;

        }

        Y.insert(P);

    }

    g<<fixed<<setprecision(6)<<d;

    return 0;

}

punct rot(punct A)

{

    return make_pair(A.second,A.first);

}

double dist(punct A,punct B)

{

    double dx=A.first-B.first;

    double dy=A.second-B.second;

    return sqrt(dx*dx+dy*dy);

}
