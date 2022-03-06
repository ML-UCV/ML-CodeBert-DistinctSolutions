#include <bits/stdc++.h>


using namespace std;



const int MAXN = 1000005;



int v[MAXN], aux[MAXN];



long long ans;



int pos1, pos2, k;



void mergesort(int st, int dr){

    if(st == dr)

        return;

    int mij = (st + dr) / 2;

    mergesort(st, mij);

    mergesort(mij + 1, dr);

    pos1 = st;

    pos2 = mij + 1;

    k = st;

    while(pos1 <= mij && pos2 <= dr){

        if(v[pos1] <= v[pos2])

            aux[k++] = v[pos1++];

        else{

            aux[k++] = v[pos2++];

            ans += mij - pos1 + 1;

            ans %= 9917;

        }

    }

    while(pos1 <= mij)

        aux[k++] = v[pos1++];

    while(pos2 <= dr)

        aux[k++] = v[pos2++];

    for(int i = st; i <= dr; ++i)

        v[i] = aux[i];

}



int main()

{

    ifstream fin("inv.in");

    ofstream fout("inv.out");

    int n;

    fin >> n;

    for(int i = 1; i <= n; ++i)

        fin >> v[i];

    mergesort(1, n);

    fout << ans;

    return 0;

}
