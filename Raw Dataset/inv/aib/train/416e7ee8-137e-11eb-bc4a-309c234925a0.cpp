#include <fstream>
#include <algorithm>




using namespace std;



ifstream fin ("inv.in");

ofstream fout ("inv.out");



struct numar {

    int id, poz;

};



int n, i, x, sol, cnt;

int A[100005], f[100005];



numar v[100005];



inline bool cmp (numar a, numar b){

    return a.id < b.id;

}



inline void update (int i){

    while (i <= n){

        A[i]++;

        i += (i&-i);

    }

}



inline int query (int i){

    int sol = 0;

    while (i){

        sol += A[i];

        i -= (i&-i);

    }

    return sol;

}



int main(){

    fin >> n;

    for (i=1; i<=n; i++){

        fin >> x;

        v[i] = {x, i};

    }

    sort (v + 1, v + n + 1, cmp);

    f[v[1].poz] = 1;

    for (i=2; i<=n; i++){

        if (v[i].id == v[i-1].id){

            cnt++;

            f[v[i].poz] = f[v[i-1].poz];

        }

        else{

            f[v[i].poz] = i - cnt;

        }

    }

    cnt = n - cnt;

    for (i=1; i<=n; i++){

        sol += (query(cnt) - query(f[i]));

        sol = sol%9917;

        update (f[i]);

    }

    fout << sol;

    return 0;

}
