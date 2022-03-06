#include <iostream>
#include <fstream>




using namespace std;



ifstream f("schi.in");

ofstream g("schi.out");



int n, n1, v[(1<<15)+10], a[(1<<15)+10], sol[(1<<15)+10], aint[2*(1<<15)+10];



void build()

{ for(int i=n; i<2*n; i++) aint[i] = a[i-n+1];

    for(int i=n-1; i; i--) aint[i] = aint[2*i] + aint[2*i+1];

}



void update(int poz)

{ poz = poz + n - 1;

    while(poz)

        { aint[poz]--;

            poz /= 2;

        }

}



int query(int nod, int val)

{ if(nod >= n) return nod-n+1;

    if(val <= aint[2*nod]) return query(2*nod, val);

    else return query(2*nod+1, val-aint[2*nod]);

}



int main()

{

    f >> n;

    n1 = n;

    for(int i=1; i<=n; i++) f >> v[i], a[i] = 1;



    if(n & (n-1))

        { int lastOne = 0;

            for(int i=0; (1<<i)<=n; i++)

                if(n & (1 << i)) lastOne = i;

            n = (1 << (lastOne + 1));

        }

    build();



    for(int i=n1; i; i--)

        { int p = query(1, v[i]);

            sol[p] = i;

            update(p);

        }

    for(int i=1; i<=n1; i++) g << sol[i] << '\n';

    return 0;

}
