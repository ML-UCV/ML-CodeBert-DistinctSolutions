#include <bits/stdc++.h>


using namespace std;



ifstream f("schi.in");

ofstream g("schi.out");



const int NMAX = 30005;

int n,arb[8 * NMAX],v[NMAX],ans[NMAX];



void build(int nod, int lo, int hi){

    if(lo == hi){

        arb[nod] = 1;

        return;

    }

    int mid = (lo + hi) / 2;

    build(2 * nod, lo , mid);

    build(2 * nod + 1, mid + 1, hi);

    arb[nod] = hi - lo + 1;

}



void update(int nod, int lo, int hi, int x, int y){

    if(lo == hi){

        arb[nod] = 0;

        ans[lo] = y;

        return;

    }

    int mid = (lo + hi) / 2;

    if(x <= arb[2 * nod])

        update(2 * nod, lo, mid, x, y);

    else

        update(2 * nod + 1, mid + 1, hi, x - arb[2 * nod], y);



    arb[nod]--;

}



int main(){

    int i;

    f >> n;

    build(1,1,n);

    for(i = 1 ; i <= n ; i++)

        f >> v[i];



    for(i = n ; i >= 1 ; i--){

        update(1,1,n,v[i],i);

    }



    for(i = 1 ; i <= n ; i++)

        g << ans[i] << "\n";





    return 0;

}
