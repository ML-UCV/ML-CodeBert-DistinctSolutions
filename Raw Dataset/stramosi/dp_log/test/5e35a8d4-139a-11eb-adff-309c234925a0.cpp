#include <fstream>


using namespace std;



int v[22][250005];



int main()

{

    ifstream cin("stramosi.in");

    ofstream cout("stramosi.out");

    int n,m;

    cin>>n>>m;

    for(int i=1;i<=n;i++)

        cin>>v[0][i];

    for(int mask=1;mask<=18;mask++)

        for(int i=1;i<=n;i++)

            v[mask][i]=v[mask-1][v[mask-1][i]];

    for(int i=1;i<=m;i++)

    {

        int x,y,ans;

        cin>>x>>y;

        ans=x;

        for(int pas=0;(1<<pas)<=y;pas++)

        {

            if(y&(1<<pas))

                ans=v[pas][ans];

        }

        cout<<ans<<"\n";

    }

    return 0;

}
