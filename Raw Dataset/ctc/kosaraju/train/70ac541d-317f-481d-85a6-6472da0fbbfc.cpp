#include <bits/stdc++.h>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");
int n, contor;



vector < int > g1[100010], g2[100010], sol[100010];

stack < int > stiva;



bitset < 100010 > viz1;

bitset < 100010 > viz2;



void read() {

    int m;

    fin >> n >> m;

    while(m--)

    {

        int x, y;

        fin >> x >> y;

        g1[x].push_back(y);

        g2[y].push_back(x);

    }

}



void DFS(int nod) {

    viz1[nod] = 1;



    for(const auto it : g1[nod]) {

        if(viz1[it] == 0) {

            DFS(it);

        }

    }

    stiva.push(nod);

}



void dfs(int nod) {

    sol[contor].push_back(nod);

    viz2[nod] = 1;



    for(const auto it : g2[nod]) {

        if(viz2[it] == 0) {

            dfs(it);

        }

    }

}





void solve() {

    for(int i=1; i<=n; i++) {

        if(viz1[i] == 0)

        {

            DFS(i);

        }

    }



    while(!stiva.empty()) {

        int nod = stiva.top();

        stiva.pop();



        if(viz2[nod] == 0) {

            contor++;

            dfs(nod);

        }

    }

}



void afis() {

    fout << contor << "\n";

    for(int i=1; i<=contor; i++)

    {

        for(const auto it : sol[i]) {

            fout << it << " ";

        }

        fout << "\n";

    }

}



int main() {

    read();

    solve();

    afis();

}
