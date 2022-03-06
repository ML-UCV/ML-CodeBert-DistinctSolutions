#include <bits/stdc++.h>
using namespace std;



ifstream f("stramosi.in");

ofstream g("stramosi.out");



const int MAX = 250005;

const int MAX_2POW = 20;



int n, m;

int ancestor[MAX][MAX_2POW + 3];



void Read()

{

    f >> n >> m;

    for(int i = 1; i <= n; ++i)

        f >> ancestor[i][0];

}



void Construct_Ancestors()

{

    for(int i = 1; i <= n; ++i)

        for(int j = 1; j <= MAX_2POW; ++j)

            if(ancestor[i][j - 1] && (1 << j) <= n)

                ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];

}



int Query(int p, int q)

{

    int exp = 0, mask = 1;



    while(mask <= p)

    {

        if(mask & p)

            q = ancestor[q][exp];

        ++exp;

        mask <<= 1;

    }



    return q;

}



void Queries()

{

    int p, q;



    while(m--)

    {

        f >> q >> p;

        g << Query(p, q) << "\n";

    }

}



int main()

{

    Read();

    Construct_Ancestors();

    Queries();

    return 0;

}
