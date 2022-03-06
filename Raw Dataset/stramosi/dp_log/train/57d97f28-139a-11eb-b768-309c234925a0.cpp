#include <fstream>


using namespace std;



ifstream in("stramosi.in");

ofstream out("stramosi.out");



int n, v[20][250001], m;



int main()

{

    in>>n>>m;

    for(int i=1; i<=n; i++)

        in>>v[0][i];

    for(int i=1; i<=18; i++)

        for(int j=1; j<=n; j++)

        v[i][j]=v[i-1][v[i-1][j]];

    while(m)

    {

        m--;

        int p,q, ans,j=0;

        in>>q>>p;

        ans=q;

        while(p)

        {

            if(p%2!=0)

                ans=v[j][ans];

            p/=2;

            j++;

        }

        out<<ans<<"\n";

    }

    return 0;

}
