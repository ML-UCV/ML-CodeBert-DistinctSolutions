#include <iostream>
#include <fstream>
#include <vector>




using namespace std;



ifstream f("stramosi.in");

ofstream g("stramosi.out");



int n, q, x;

int log2[250005];

int s[20][250005];



void build()

{

    for (int i = 1; (1<<i) <= n; i++)

    {

        for (int j = 1; j <= n; j++)

            s[i][j]=s[i-1][s[i-1][j]];

    }

}



int main()

{

    f >> n >> q;

    for (int i = 1; i <= n; i++)

    {

        f >> x;

        s[0][i]=x;

    }

    build();

    while(q--)

    {

        int x, y;

        f >> x >> y;

        for (int i = 0; i <= 20; i++)

            if(y&(1<<i)) x=s[i][x];

        g << x << '\n';

    }

    return 0;

}
