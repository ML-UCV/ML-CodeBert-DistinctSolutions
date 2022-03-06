#include <bits/stdc++.h>


using namespace std;



ifstream fin ("schi.in");

ofstream fout ("schi.out");



int n, i, a;

int aib[30005], v[30005], sol[30005];



int query (int poz){

    int sol = 0;

    for (;poz>=1;poz-=(poz&(-poz))){

        sol += aib[poz];

    }

    return sol;

}



void update (int poz, int val){

    for (;poz<=n;poz+=(poz&(-poz))){

        aib[poz] += val;

    }

}



int cautareBinara (int x){

    int st, dr, mid, sol = INT_MAX;

    st = 1, dr = n;

    while (st <= dr){

        mid = st + (dr - st)/2;

        if (x == query(mid)){

            sol = min (sol, mid);

        }

        if (x <= query(mid)){

            dr = mid - 1;

        }

        else{

            st = mid + 1;

        }

    }

    return sol;

}



int main(){

    fin >> n;

    for (i=1; i<=n; i++){

        fin >> v[i];

        update (i, 1);

    }

    for (i=n; i>=1; i--){

        a = cautareBinara (v[i]);

        update (a, -1);

        sol[a] = i;

    }

    for (i=1; i<=n; i++){

        fout << sol[i] << "\n";

    }

    return 0;

}
