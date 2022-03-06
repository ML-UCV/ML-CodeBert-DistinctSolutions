#include <bits/stdc++.h>







using namespace std;



const long long nmax = 100005;



long long n,m,_curr = -1;

vector<long long>nod[nmax],nod_R[nmax],vecc,scc[nmax];

bitset<nmax>viz;



void DFS(long long s){

    viz[s] = 1;

    for(auto it : nod[s]){

        if(!viz[it]){

            DFS(it);

        }

    }

    vecc.push_back(s);

}



void DFS2(long long s){

    viz[s] = 1;

    scc[_curr].push_back(s);

    for(auto it : nod_R[s]){

        if(!viz[it]){

            DFS2(it);

        }

    }

}



int32_t main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);

    srand(chrono::steady_clock::now().time_since_epoch().count());

    freopen("ctc.in","r",stdin);

    freopen("ctc.out","w",stdout);

    cin >> n >> m;

    for(long long i=1;i<=m;i++){

        long long x,y;

        cin >> x >> y;

        nod[x].push_back(y);

        nod_R[y].push_back(x);

    }

    for(long long i=1;i<=n;i++){

        if(!viz[i]) DFS(i);

    }

    viz.reset();

    reverse((vecc).begin(), (vecc).end());

    for(auto it : vecc){

        if(!viz[it]){

            ++_curr;

            DFS2(it);

        }

    }

    cout << (_curr + 1LL) << '\n';

    for(long long i=0;i<=_curr;i++){

        for(auto it : scc[i]) cout << it << ' ';

        cout << '\n';

    }

}
