#include <bits/stdc++.h>
using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

const int Dim=2e6+2;

int dp[Dim],dp2[Dim],K,cnt;



vector < int > V;



int main()

{

    string A,B;

    f>>A>>B;



    int lgA=A.size(),lgB=B.size();

    for(int i=lgA;i>=1;i--) A[i]=A[i-1];

    for(int i=lgB;i>=1;i--) B[i]=B[i-1];



    dp[1]=0;

    for(int i=2;i<=lgA;i++)

    {

        K=dp[i-1];

        while( K>0 && A[K+1]!=A[i] ) K=dp[K];



        dp[i]=K+(A[K+1]==A[i]);

    }



    dp2[0]=0;

    for(int i=1;i<=lgB;i++)

    {

        K=dp2[i-1];

        while( K>0 && A[K+1]!=B[i] ) K=dp[K];



        dp2[i]=K+(A[K+1]==B[i]);



        if(dp2[i]==lgA)

        {

            cnt++;

            if( cnt <= 1000 ) V.push_back(i-lgA);

        }

    }



    g<<cnt<<'\n';

    for(int i=0;i<V.size();i++) g<<V[i]<<' ';



    return 0;

}
