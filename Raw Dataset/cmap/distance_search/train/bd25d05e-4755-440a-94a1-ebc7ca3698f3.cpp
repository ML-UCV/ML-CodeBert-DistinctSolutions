#include<fstream>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
using namespace std;



long long solve(const int& n,vector<pair<int,int> >& pct)

{

    sort(pct.begin(),pct.end());

    set<pair<int,int> > s;



    int j=0;

    long long dc=1e18;

    for(int i=0;i<n;++i)

    {



        int d = ceil(sqrt(dc));

        while(pct[i].first-pct[j].first>=d){

            pair<int,int> ds=make_pair(pct[j].second,pct[j].first);

            s.erase(ds);

            ++j;

        }



        set<pair<int,int> >::iterator jos = s.lower_bound(make_pair(pct[i].second-d,pct[i].first));

        set<pair<int,int> >::iterator sus = s.lower_bound(make_pair(pct[i].second+d,pct[i].first));



        for(auto& it=jos;it!=sus;++it)

        {

            int dx=pct[i].first-it->second;

            int dy=pct[i].second-it->first;

            dc=min(dc,1ll*dx*dx+1ll*dy*dy);

        }



        s.insert(make_pair(pct[i].second,pct[i].first));

    }

    return dc;

}



int main()

{

    ifstream fin("cmap.in");

    ofstream fout("cmap.out");

    int n;

    fin>>n;

    vector<pair<int,int> > p(n);

    for(int i=0;i<n;++i)

        fin>>p[i].first>>p[i].second;

    fout<<fixed<<setprecision(6)<<sqrt(solve(n,p));

    fin.close();

    fout.close();

}
