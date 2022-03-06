#include <bits/stdc++.h>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int nmax = 100005;

int n, m, id[nmax], low[nmax], z;

bool inStack[nmax];

vector <int> G[nmax];

stack <int> s;

vector <vector <int> > ans;

void tarjan(int nod){

    id[nod] = low[nod] = ++z;

    s.push(nod);

    inStack[nod] = true;

    for (auto it : G[nod]){

        if (id[it] == 0){

            tarjan(it);

            low[nod] = min(low[nod], low[it]);

        }

        else{

            if (inStack[it]){

                low[nod] = min(low[nod], id[it]);

            }

        }

    }

    if (id[nod] == low[nod]){

        vector <int> aux;

        int snod;

        do{

            snod = s.top();

            inStack[snod] = false;

            s.pop();

            aux.push_back(snod);

        } while (snod != nod);

        ans.push_back(aux);

    }

}



int main(){

    fin >> n >> m;

    for (int i = 1; i <= m; ++i){

        int x, y;

        fin >> x >> y;

        G[x].push_back(y);

    }

    for (int i = 1; i <= n; ++i){

        if (id[i] == 0){

            tarjan(i);

        }

    }

    fout << ans.size() << "\n";

    for (int i = 0; i < ans.size(); ++i){

        for (int j = 0; j < ans[i].size(); ++j){

            fout << ans[i][j] << " ";

        }

        fout << "\n";

    }

    fin.close();

    fout.close();

    return 0;

}
