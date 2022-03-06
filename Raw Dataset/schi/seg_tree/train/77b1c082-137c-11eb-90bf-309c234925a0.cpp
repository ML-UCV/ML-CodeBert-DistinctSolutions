#include <bits/stdc++.h>


using namespace std;



int n,v[30005],pom[120005],ans[30005];



void build(int nod, int st, int dr) {

    if (st == dr) {

        pom[nod] = 1;

        return;

    }

    int md = (st + dr) / 2;

    build(nod * 2, st, md);

    build(nod * 2 + 1, md + 1, dr);

    pom[nod] = pom[nod * 2] + pom[nod * 2 + 1];

}

void update(int nod, int st, int dr, int x) {

    if (st == dr) {

        pom[nod] = 0;

        return;

    }

    int md = (st + dr) / 2;

    if (md >= x)

        update(nod * 2, st, md, x);

    else

        update(nod * 2 + 1, md + 1, dr, x);

    pom[nod] = pom[nod * 2] + pom[nod * 2 + 1] ;

}

int querry(int nod, int st, int dr, int x) {

    if(st == dr)

        return st;

    int md = (st + dr) / 2;

    if (pom[nod * 2] < x)

        return querry(nod * 2 + 1, md + 1, dr, x - pom[nod * 2]) ;

    else

        return querry(nod * 2, st, md, x) ;

}

int main() {

    ifstream fin("schi.in");

    ofstream fout("schi.out");

    int poz;

    fin >> n;

    for (int i = 1;i <= n;i++)

        fin >> v[i];

    build(1, 1, n);

    for (int i = n;i > 0;i--) {

        poz = querry(1, 1, n, v[i]);

        ans[poz] = i;

        update(1, 1, n, poz);

    }

    for (int i = 1;i <= n;i++)

        fout << ans[i] << '\n';

    return 0;

}
