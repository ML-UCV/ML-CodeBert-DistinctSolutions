#include <iostream>
#include<fstream>


using namespace std;



int strm[20][250005];



int main()

{

    ifstream cin("stramosi.in");

    ofstream cout("stramosi.out");

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int n, m, i, j, p, q;

    cin>>n>>m;

    for (i=1; i<=n; i++)

        cin>>strm[0][i];

    for (j=1; j<=18; j++)

        for (i=1; i<=n; i++)

            strm[j][i]=strm[j-1][strm[j-1][i]];

    for (i=1; i<=m; i++)

    {

        cin>>p>>q;

        for (j=0; j<=18; j++)

            if(q&(1<<j))

                p=strm[j][p];

        cout<<p<<"\n";

    }

    return 0;

}
