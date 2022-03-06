#include <bits/stdc++.h>




using namespace std;



const int NMAX = 2e5 + 5;



int n , m , u , v , c , node , nxt , f[NMAX] , ans_cost;

vector <pair<int,int> > g[NMAX] , ans;

priority_queue <pair< int , pair<int,int> > , vector <pair< int , pair<int,int> > > , greater <pair< int , pair<int,int> > > > Q;

pair< int , pair<int,int> > p;

int main()

{

    ifstream cin("apm.in");

    ofstream cout("apm.out");



    cin >> n >> m;

    for(int i = 0; i < m; i++)

    {



        cin >> u >> v >> c;

        g[u].push_back({v , c});

        g[v].push_back({u , c});



    }



    Q.push({0 , {0 , 1} });

    while(!Q.empty())

    {



        p = Q.top();

        Q.pop();



        node = p.second.second;



        if(f[node])continue;

        ans.push_back({p.second.first , node});

        f[node] = 1;



        ans_cost += p.first;

        for(int i = 0; i < g[node].size(); i++)

            Q.push({g[node][i].second , {node , g[node][i].first} });

    }



    cout << ans_cost << "\n";

    cout << ans.size() - 1 << "\n";

    for(int i = 1; i < ans.size(); i++)

        cout << ans[i].first << " " << ans[i].second << "\n";

    return 0;

}
