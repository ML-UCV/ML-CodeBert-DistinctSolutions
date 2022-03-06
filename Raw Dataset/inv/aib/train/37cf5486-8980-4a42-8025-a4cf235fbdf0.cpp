#include <bits/stdc++.h>


using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");



static inline int UB (int X)

{

    return (X&(-X));

}



const int NMAX=1e5+5, MOD=9917;



int A[NMAX], N;



int AIB[NMAX];



inline void Update (int poz, int val)

{

    for(int i=poz; i<=N; i+=UB(i))

        AIB[i]+=val;



    return;

}



static inline int Query (int poz)

{

    int ans=0;



    for(int i=poz; i>=1; i-=UB(i))

        ans+=AIB[i];



    return ans;

}



int B[NMAX], C[NMAX];



inline void Read ()

{

    f.tie(NULL);



    f>>N;



    for(int i=1; i<=N; ++i)

    {

        f>>A[i];



        B[i]=A[i];

    }



    return;

}



inline void Normalize ()

{

    sort(B+1, B+N+1);



    C[++C[0]]=B[1];



    for(int i=2; i<=N; ++i)

        if(B[i] != B[i-1])

            C[++C[0]]=B[i];



    for(int i=1; i<=N; ++i)

        A[i]=(lower_bound(C+1, C+C[0]+1, A[i])-C);



    return;

}



inline void Solve ()

{

    int ans=0;



    for(int i=N; i>=1; --i)

    {

        ans+=Query(A[i]-1);



        Update(A[i], 1);



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
