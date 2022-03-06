#include <fstream>


using namespace std;



ifstream in("schi.in");

ofstream out("schi.out");



const int N = 1 << 17, M = 30001;



int t[N], concurent, poz, rez[M], v[M];



void update(int p, int st, int dr)

{

    if(st == dr)

    {

        rez[st] = concurent;

        t[p]++;

        return;

    }

    int m = (st+dr) / 2;

    int libere = m - st + 1 - t[2*p];

    if(poz <= libere)

        update(2*p, st, m);

    else

    {

        poz -= libere;

        update(2*p+1, m + 1, dr);

    }

    t[p] = t[2*p] + t[2*p + 1];

}



int main()

{

    int n;

    in >> n;

    for(int i = 1; i <= n; i++)

    {

        in >> v[i];

    }

    for(int i = n; i >= 1; i--)

    {

        concurent = i;

        poz = v[i];

        update(1, 1, n);

    }

    for(int i = 1; i <= n; i++)

    {

        out << rez[i] << "\n";

    }

    return 0;

}
