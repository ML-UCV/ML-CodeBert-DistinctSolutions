#include <bits/stdc++.h>








using namespace std;



const long long mod=1e9+7;

const long long modu=1999999973;

const long long modul=998244353;



const long long nmax=1000005;



long long n;

long double ans=1e18;

pair<long long,long long>a[100005];



long double dist(long long x,long long y,long long z,long long t){

    long double g = sqrt((long double)((x-z)*(x-z)+(y-t)*(y-t)));

    return g;

}



int32_t main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);

    srand(chrono::steady_clock::now().time_since_epoch().count());

    ifstream cin("cmap.in");

    ofstream cout("cmap.out");

    cout << fixed << setprecision(12);

    cin >> n;

    for(long long i=1;i<=n;i++) cin >> a[i].first >> a[i].second;

    sort(a+1,a+n+1);

    set<pair<long long,long long>>q;

    long long indx=1;

    for(long long i=1;i<=n;i++){

            while(q.size()>=1 && (long double)(a[i].first-a[indx].first)>=ans){

                q.erase(q.find({a[indx].second,a[indx].first}));

                indx++;

            }

            auto it1=q.lower_bound({(long double)(a[i].second-ans),(long double)(a[i].first)});

            auto it2=q.upper_bound({(long double)(a[i].second+ans),(long double)(a[i].first)});

            auto it=it1;

            while(it!=it2){

                if(it==q.end()) break;

                long long x=it->second;

                long long y=it->first;

                ans=min(ans,dist(x,y,a[i].first,a[i].second));

                it++;

            }

            q.insert({a[i].second,a[i].first});

    }

    cout << ans << '\n';

}
