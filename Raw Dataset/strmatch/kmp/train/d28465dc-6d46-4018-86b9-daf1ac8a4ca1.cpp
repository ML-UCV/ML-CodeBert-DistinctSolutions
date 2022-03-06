#include <bits/stdc++.h>
using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

const int Dim=2e6+5;

const int Mod1=1e6+7;

const int Mod2=1e6+21;

const int d=91;



void P1()

{

    int ans=0;

    string A,B;

    f>>A>>B;

    int N=A.size(),M=B.size();

    for(int i=N;i>=1;i--) A[i]=A[i-1];

    for(int i=M;i>=1;i--) B[i]=B[i-1];



    vector < int > dp1(N+1),dp2(M+1),V;

    dp1[1]=0;

    for(int i=2;i<=N;i++)

    {

        int K=dp1[i-1];

        while( K>0 && A[K+1]!=A[i] ) K=dp1[K];



        dp1[i]=K + (A[K+1]==A[i]);

    }

    dp2[0]=0;

    for(int i=1;i<=M;i++)

    {

       int K=dp2[i-1];

       while( K>0 && A[K+1]!=B[i] ) K=dp1[K];



       dp2[i]=K+(A[K+1]==B[i]);



       if(dp2[i]==N)

       {

           ans++;

           if(ans<=1000) V.push_back(i-N);

       }

    }

    g<<ans<<'\n';

    for(unsigned int i=0;i<V.size();i++) g<<V[i]<<' ';



}



void P2()

{

    string A,B;

    f>>A>>B;

    int ans=0;

    int hashP1=0,hashP2=0,hashS1=0,hashS2=0,cos1=1,cos2=1;

    int N=A.size(),M=B.size();



    vector < int > V;



    for(int i=0;i<N;i++)

    {

        hashP1=((hashP1*d)%Mod1+A[i])%Mod1;

        hashP2=((hashP2*d)%Mod2+A[i])%Mod2;



        if(i)

        {

            cos1=(cos1*d)%Mod1;

            cos2=(cos2*d)%Mod2;

        }

    }



    for(int i=0;i<N;i++)

    {

        hashS1=((hashS1*d)%Mod1+B[i])%Mod1;

        hashS2=((hashS2*d)%Mod2+B[i])%Mod2;

    }



    if(hashS1==hashP1&&hashS2==hashP2)

    {

        ans++;

        V.push_back(0);

    }

    for(int i=N;i<M;i++)

    {

        hashS1=( ( ( hashS1 - B[i-N]*cos1 )%Mod1 + Mod1 )*d + B[i] )%Mod1;

        hashS2=( ( ( hashS2 - B[i-N]*cos2 )%Mod2 + Mod2 )*d + B[i] )%Mod2;



        if(hashS1==hashP1&&hashS2==hashP2)

        {

            ans++;

            if(ans<=1005) V.push_back(i-N+1);

        }

    }

    g<<ans<<'\n';

    for(unsigned int i=0;i<V.size();i++) g<<V[i]<<' ';



}



int main()

{

P1();

    return 0;

}
