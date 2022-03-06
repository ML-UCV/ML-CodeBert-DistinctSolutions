#include <bits/stdc++.h>


using namespace std;

ifstream in("schi.in");

ofstream out("schi.out");

const int NMAX = 30005;

int fn[NMAX],v[NMAX],rez[NMAX],n;

void add(int k, int val)

{

    while (k<=n)

    {

        fn[k]+=val;

        k+=k&-k;

    }

}



int find(int val)

{

    int step,i;

    for (step = 1; step<=n; step<<=1);

    for (i = 0; step>0; step>>=1)

        if (i+step<=n && fn[i+step]<val)

        {

            i+=step;

            val-=fn[i];

        }

    return i+1;

}



int main()

{

    in >> n;

    for (int i = 1; i<=n; i++)

    {

        in >> v[i];

        add(i,1);

    }

    for (int i = n; i>=1; i--)

    {

        int poz = find(v[i]);

        rez[poz] = i;

        add(poz,-1);

    }

    for (int i = 1; i<=n; i++)

        out << rez[i] << "\n";

}
