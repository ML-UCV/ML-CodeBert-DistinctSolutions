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

int sum(int k)

{

    int s = 0;

    while (k>0)

    {

        s+=fn[k];

        k-=k&-k;

    }

    return s;

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

        int x = v[i],r;

        int st = 1, dr = n;

        while (st<=dr)

        {

            int mj = (st+dr)/2;

            int s = sum(mj);

            if (s == x)

            {

                r = mj;

                dr = mj-1;

            }

            else if (s>x)

                dr = mj-1;

            else

                st = mj+1;

        }

        rez[r] = i;

        add(r,-1);

    }

    for (int i = 1; i<=n; i++)

        out << rez[i] << "\n";

}
