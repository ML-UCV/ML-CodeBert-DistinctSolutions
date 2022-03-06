#include<bits/stdc++.h>
using namespace std;



int n, m, a, b, c, F = 101, T = 102, viz[202], uz[202];

vector<int> v[2 * 202], v2[2 * 202], H, ans;



void dfs(int nod){

    uz[nod] = 1;

    for (auto it : v[nod]) if (!uz[it]) dfs(it);

    H.push_back(nod);

}



void dfs2(int nod){



    uz[nod] = 0; viz[nod ^ 1] = 1;

    if (nod&1) ans.push_back(nod/2 + 1);

    for (auto it : v2[nod]) if (uz[it]) dfs2(it);

}



void add(int a, int b){

    a = (a < 0 ? -a * 2 - 1 : a * 2 - 2);

    b = (b < 0 ? -b * 2 - 1 : b * 2 - 2);





    v[a^1].push_back(b);

    v[b^1].push_back(a);

    v2[a].push_back(b^1);

    v2[b].push_back(a^1);

}



int main(){

    freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);



    cin >> n >> m;





    for (int i=1;i<=m;i++){

        cin >> a >> b >> c;

        if (c == 0){

            add(a, b);

        }

        else if (c == 1){

            add(a, -b);

        }

        else if (c == 2){

            add(-a, b);

        }

        else{

            add(-a, -b);

        }

    }



    for (int i=0;i<2*n;i++) if (!uz[i]) dfs(i);

    reverse(H.begin(), H.end());

    for (auto it : H){



        if (uz[it] && uz[it^1]) dfs2(it);

    }



    cout << ans.size() << '\n';

    for (auto it : ans)

        cout << it << '\n';







    return 0;

}
