#include <bits/stdc++.h>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

int dp[2000010],dpp[2000010],N,M,K,ans,S[1001];

char A[2000010],B[2000010];



int main()

{

    f>>A>>B;

    N=strlen(A); M=strlen(B);



    for(int i=N-1;i>=0;i--) A[i+1]=A[i];

    for(int i=M-1;i>=1;i--) B[i+1]=B[i];



    dp[1]=0;

    for(int i=2;i<=N;i++)

    {

        K=dp[i-1];

        while( K > 0 && A[i] != A[ K + 1 ] ) K=dp[K];



        if( A[i] == A[ K + 1 ] ) dp[i]=K+1;

    }



    dpp[0]=0;

    for(int i=1;i<=M;i++)

    {

        K=dpp[i-1];

        while( K > 0 && B[i] != A[ K + 1 ] ) K=dp[K];

        if( B[i] == A[ K + 1 ] ) dpp[i]=K+1;



        if( dpp[i] == N )

        {

            ans++;

            if(ans<=1000) S[ans]=i-N;

        }

    }

    g<<ans<<'\n';

    for(int i=1;i<=min(ans,1000);i++) g<<S[i]<<' ';



    return 0;

}
