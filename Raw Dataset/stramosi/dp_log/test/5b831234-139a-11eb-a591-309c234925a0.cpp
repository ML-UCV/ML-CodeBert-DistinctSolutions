#include <bits/stdc++.h>




using namespace std;

ifstream fin ("stramosi.in");

ofstream fout ("stramosi.out");

int t[18][250005], n, q, x, y;

int main()

{

    fin >> n >> q;

    for(int i=1;i<=n;i++)

        fin >> t[0][i];



    for(int j=1;j<=17;j++)

        for(int i=1;i<=n;i++)

            t[j][i]=t[j-1][t[j-1][i]];



    for(int i=1;i<=q;i++)

    {

        fin >> x >> y;

        for(int j=17;j>=0;j--)

            if((1<<j)<=y)

                {

                    y=y-(1<<j);

                    x=t[j][x];

                }

        fout << x << '\n';

    }

    return 0;

}
