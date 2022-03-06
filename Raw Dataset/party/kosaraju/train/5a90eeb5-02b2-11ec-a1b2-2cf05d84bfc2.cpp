#include <bits/stdc++.h>


using namespace std;

ifstream f("party.in");

ofstream g("party.out");



const int NMax = 202;



int n,m,x,y,p,top,wrong;

int viz[NMax],ans[NMax],s[NMax];

vector<int> G[NMax],GT[NMax],v;



int non(int x){

    if(x <= n)

        return x + n;

    return x - n;

}

void dfs(int nod){

    viz[nod] = 1;

    for(int i = 0; i < G[nod].size(); ++i){

        if(!viz[G[nod][i]]){

            dfs(G[nod][i]);

        }

    }

    s[++top] = nod;

}

void dfsT(int nod){

    viz[nod] = 0;

    ans[nod] = 0;

    ans[non(nod)] = 1;

    for(int i = 0; i < GT[nod].size(); ++i){

        if(viz[GT[nod][i]]){

            dfsT(GT[nod][i]);

        }

    }

}

int main()

{

    f >> n >> m;

    for(int i = 1; i <= m; ++i){

        f >> x >> y >> p;

        if(p == 0){

            G[non(x)].push_back(y);

            G[non(y)].push_back(x);

            GT[y].push_back(non(x));

            GT[x].push_back(non(y));

        }

        if(p == 1){

            G[non(x)].push_back(non(y));

            G[y].push_back(x);

            GT[non(y)].push_back(non(x));

            GT[x].push_back(y);

        }

        if(p == 2){

            G[x].push_back(y);

            G[non(y)].push_back(non(x));

            GT[y].push_back(x);

            GT[non(x)].push_back(non(y));

        }

        if(p == 3){

            G[x].push_back(non(y));

            G[y].push_back(non(x));

            GT[non(y)].push_back(x);

            GT[non(x)].push_back(y);

        }

    }

    for(int i = 1; i <= 2 * n; ++i){

        if(!viz[i]){

            dfs(i);

        }

    }

    for(int i = top; i >= 1; --i){

        if(viz[s[i]] && viz[non(s[i])]){

            dfsT(s[i]);

        }

    }

    vector<int> v;

    for(int i = 1; i <= n; ++i){

        if(ans[i])

            v.push_back(i);

    }

    g << v.size() << '\n';

    for(int i = 0; i < v.size(); ++i){

        g << v[i] << '\n';

    }

    return 0;

}
