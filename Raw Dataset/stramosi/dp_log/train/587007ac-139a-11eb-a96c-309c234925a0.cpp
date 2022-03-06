#include <fstream>
using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

int N,M,P,Q,dp[21][250005];

int rasp(int a,int b)

{

    int nod=a;

    for(int i=0; (1<<i)<=b; i++)

        if((1<<i)&b)

            nod=dp[i][nod];

    return nod;

}

int main()

{

    fin>>N>>M;

    for(int i=1; i<=N; i++)

        fin>>dp[0][i];

    for(int j=1; j<=N; j++)

    {

        for(int i=1; i<=20; i++)

        {

            dp[i][j]=dp[i-1][dp[i-1][j]];

        }

    }

    for(int i=1; i<=M; i++)

    {

        fin>>Q>>P;

        fout<<rasp(Q,P)<<"\n";

    }

    return 0;

}
