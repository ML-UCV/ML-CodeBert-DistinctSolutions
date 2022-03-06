#include<fstream>
#include<stack>
#include<vector>
using namespace std;

int n, m, i, t, x, y, nr, cnt, num, j;

int viz[205], ff[205], f[205], ctc[205], low[205], niv[205], sol[205];

stack<int> s;

vector<int> v[205], w[205];

ifstream fin("party.in");

ofstream fout("party.out");

int inv(int x){

    if(x > n){

        return x - n;

    }

    return x + n;

}

void dfs(int nod){

    viz[nod] = f[nod] = 1;

    cnt++;

    low[nod] = niv[nod] = cnt;

    s.push(nod);

    for(int i = 0; i < v[nod].size(); i++){

        int vecin = v[nod][i];

        if(viz[vecin] == 0){

            dfs(vecin);

        }

        if(f[vecin] == 1){

            low[nod] = min(low[nod], low[vecin]);

        }

    }

    if(low[nod] == niv[nod]){

        nr++;

        int x;

        do{

            x = s.top();

            s.pop();

            ctc[x] = nr;

            f[x] = 0;

            w[nr].push_back(x);

        }while(x != nod);

    }

}

int main(){

    fin>> n >> m;

    for(i = 1; i <= m; i++){

        fin>> x >> y >> t;

        if(t == 1){

            y = inv(y);

        }

        else{

            if(t == 2){

                x = inv(x);

            }

            else{

                if(t == 3){

                    x = inv(x);

                    y = inv(y);

                }

            }

        }

        v[ inv(x) ].push_back(y);

        v[ inv(y) ].push_back(x);

    }

    for(i = 1; i <= n + n; i++){

        if(viz[i] == 0){

            dfs(i);

        }

    }

    for(i = 1; i <= nr; i++){

        if(ff[i] == 1){

            continue;

        }

        for(j = 0; j < w[i].size(); j++){

            x = w[i][j];

            sol[x] = 1;

            sol[ inv(x)] = 0;

            ff[ ctc[ inv(x) ] ] = 1;

        }

    }

    for(i = 1; i <= n; i++){

        num += sol[i];

    }

    fout<< num <<"\n";

    for(i = 1; i <= n; i++){

        if(sol[i] == 1){

            fout<< i <<"\n";

        }

    }

    return 0;

}
