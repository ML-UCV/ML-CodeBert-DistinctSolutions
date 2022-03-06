#include <fstream>


using namespace std;



int dp[19][250005];



int main()

{

    ifstream cin("stramosi.in");

    ofstream cout("stramosi.out");

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int n, q, nod, dist, i, j;

    cin >> n >> q;

    for(i=1; i<=n; i++) cin >> dp[0][i];

    for(i=1; i<=18; i++)

        for(j=1; j<=n; j++) dp[i][j] = dp[i-1][dp[i-1][j]];

    for(j=1; j<=q; j++)

        { cin >> nod >> dist;

            for(i=0; i<=18; i++) if(dist&(1<<i)) nod = dp[i][nod];

            cout << nod << '\n';

        }

    return 0;

}
