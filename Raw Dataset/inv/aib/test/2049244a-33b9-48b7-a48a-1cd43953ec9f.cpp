#include <fstream>
#include <algorithm>


using namespace std;



const int NMAX = 100001,

          MOD = 9917;



struct numar

{

    int poz, val;

};



int N, AiB[NMAX];

numar v[NMAX];



ifstream f("inv.in");

ofstream g("inv.out");



bool comp(const numar &a, const numar &b)

{

    if(a.val == b.val)

        return a.poz < b.poz;

    else

        return a.val < b.val;

}



void add(int poz)

{

    while(poz <= N)

    {

        AiB[poz]++;

        poz += poz & (-poz);

    }

}



int sum(int poz)

{

    int s = 0;

    while(poz > 0)

    {

        s += AiB[poz];

        poz -= poz & (-poz);

    }

    return s;

}



int main()

{

    int x, i;

    f >> N;

    for(i = 1; i <= N; i++)

    {

        f >> x;

        v[i].poz = i;

        v[i].val = x;

    }

    sort(v + 1, v + N + 1, comp);

    long long nrInv = 1LL * N * (N - 1) / 2;

    for(i = 1; i <= N; i++)

    {

        x = v[i].poz;

        nrInv -= sum(x);

        add(x);

    }

    g << nrInv % MOD;

    return 0;

}
