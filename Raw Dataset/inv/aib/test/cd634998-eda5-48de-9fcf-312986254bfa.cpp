#include <bits/stdc++.h>


using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");



const int NMAX=1e5+5, MOD=9917;



int A[NMAX], AIB[NMAX], N, B[NMAX], Sol[NMAX];



inline int UB (int X)

{

    return (X&(-X));

}



inline void Update (int poz, int val)

{

    for(int i=poz; i<=N; i+=UB(i))

        AIB[i]+=val;

}



inline int Query (int poz)

{

    int ans=0;



    for(int i=poz; i>=1; i-=UB(i))

        ans+=AIB[i];



    return ans;

}



inline void Read ()

{

    f.tie(NULL);



    f>>N;



    for(int i=1; i<=N; ++i)

    {

        f>>A[i];



        B[i]=A[i];

    }

}



inline void Normalize ()

{

    sort(B+1, B+N+1);



    Sol[++Sol[0]]=B[1];



    for(int i=2; i<=N; ++i)

        if(B[i] != B[i-1])

            Sol[++Sol[0]]=B[i];



    for(int i=1; i<=N; ++i)

        A[i]=lower_bound(Sol+1, Sol+Sol[0]+1, A[i])-Sol;

}



inline void Solve ()

{

    int ans=0;



    for(int i=1; i<=N; ++i)

    {

        int X=i-1-Query(A[i]);



        Update(A[i], 1);



        ans+=X;



        ans%=MOD;

    }



    g<<ans<<'\n';



    exit(0);

}



int main()

{

    Read();



    Normalize();



    Solve();



    return 0;

}
