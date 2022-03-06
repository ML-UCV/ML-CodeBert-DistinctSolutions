#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <fstream>
#include <bitset>
#include <set>
#include <map>
#include <ctime>
#include <list>
#include <cstring>
using namespace std;

ifstream cin("data"".in");

ofstream cout("data"".out");



template<class a, class type>

void print(a v, type t) {

    for_each(v.begin(),v.end(), [](type x) { cout << x << ' '; });

    cout << '\n';

}



struct nod {

    vector<int> v1;

    vector<int> v2;

};



int n, m;

nod v[2 * 207 + 1];

stack<int> s;

bitset<2*207> viz;

vector<vector<int> > componente;

int nrP;

inline void add(const int &ind,const int &next){

    v[ind].v1.push_back(next);

    v[next].v2.push_back(ind);

}

void dfs(int i){

    viz[i] = 1;

    for(auto it = v[i].v1.begin();it!=v[i].v1.end();++it){

        if(!viz[*it])

            dfs(*it);

    }

    s.push(i);

}

int nrGr;

void dfs_inv(int i){

    viz[i] = 1;

    componente[nrGr].emplace_back(i);

    for(auto it = v[i].v2.begin();it!=v[i].v2.end();++it){

        if(!viz[*it])

            dfs_inv(*it);

    }

}

inline int negat(int nr){

    return (nr<=n?nr+n:nr-n);

}

int main() {

    ios_base::sync_with_stdio(false);

    clock_t tStart = clock();

    cin >> n >> m;

    int x1,x2,cod;

    for(int i=0;i<m;++i){

        cin >> x1 >> x2 >> cod;

        if(!cod){

            add(negat(x1),x2);

            add(negat(x2),x1);

        } else if(cod == 1){

            add(negat(x1),negat(x2));

            add(x2,x1);

        } else if(cod == 2) {

            add(x1,x2);

            add(negat(x2),negat(x1));

        } else if (cod == 3){

            add(x1,negat(x2));

            add(x2,negat(x1));

        }

    }

    for(int i=1;i<=2*n;++i){

        if(!viz[i])

            dfs(i);

    }

    viz.reset();

    vector<int> temp;

    componente.push_back(temp);

    while(!s.empty()){

        if(!viz[s.top()]){

            componente.push_back(temp);

            ++nrGr;

            dfs_inv(s.top());

        }

        s.pop();

    }



    vector<int> sol(2*207,-1);



    for(int i = nrGr;i;--i){

        if(sol[componente[i][0]] == -1){

            for(auto it = componente[i].begin();it != componente[i].end(); ++it){

                sol[*it] = 1;

                sol[negat(*it)] = 0;
            }

        }

    }



    for(int i=1;i<=n;++i){

        if(sol[i]<0){

            sol[i] = 1;

        }

        nrP += sol[i];

    }

    cout << nrP << '\n';

    for (int i = 1; i <= n; ++i) {

        if (sol[i])

            cout << i << '\n';

    }

    cout.close();

    printf("\nTime taken: %.2fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);

}
