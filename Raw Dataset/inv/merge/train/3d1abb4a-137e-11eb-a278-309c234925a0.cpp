#include <iostream>
#include <fstream>
using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");

const int N = 100001;

int n, v[N];

long long inv;

void intercls (int v[], int st, int mij, int dr){

    int i = st, j = mij + 1, k = 0;

    int v2[N];

    while(i <= mij && j <= dr){

        if(v[i] <= v[j]) {

            v2[k ++] = v[i ++];

        }

        else {

            v2[k ++] = v[j ++];

            inv=(inv + mij-i+1)%9917;

        }

    }

    while(i <= mij)

        v2[k ++] = v[i ++];

    while(j <= dr)

        v2[k ++] = v[j ++];

    int c=0;

    for(int i=st; i<=dr; i++)

        v[i]=v2[c++];

}

void mergesort (int v[], int st, int dr){

    if(st < dr){

        int mij = (st + dr) / 2;

        mergesort (v, st, mij);

        mergesort (v, mij + 1, dr);

        intercls (v, st, mij, dr);

    }

}

int main()

{

    f >> n;

    for(int i = 1; i <= n; i ++)

        f >> v[i];

    mergesort (v, 1, n);

    g << inv;

    return 0;

}
