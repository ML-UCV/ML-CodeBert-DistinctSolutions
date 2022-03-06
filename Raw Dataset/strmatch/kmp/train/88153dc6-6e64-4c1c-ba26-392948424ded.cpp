#include <fstream>
#include <cstring>




using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



const int NMAX = 2e6 + 5;



int N, M, Size, Z[(NMAX << 1)];



char A[NMAX], B[NMAX], S[(NMAX << 1)];



int V[NMAX], cnt = 0;



static inline void Read ()

{

    f.tie(nullptr);



    f >> (A + 1) >> (B + 1);



    N = (int)strlen(A + 1), M = (int)strlen(B + 1);



    return;

}



static inline void Build ()

{

    for(int i = 1; i <= N; ++i)

        S[++Size] = A[i];



    S[++Size] = '#';



    for(int i = 1; i <= M; ++i)

        S[++Size] = B[i];



    return;

}



static inline void Precalculation ()

{

    Build();



    Z[1] = Size;



    int Left = 0, Right = 0;



    for(int i = 2; i <= Size; ++i)

    {

        if(i <= Right)

            Z[i] = min(Z[(i - Left + 1)], Right - i + 1);

        else

            Z[i] = 0;



        while(i + Z[i] <= Size && S[(i + Z[i])] == S[(Z[i] + 1)])

            ++Z[i];



        if(i + Z[i] - 1 >= Right)

            Left = i, Right = i + Z[i] - 1;

    }



    return;

}



static inline void Solve ()

{

    for(int i = N + 2; i <= Size; ++i)

        if(Z[i] == N)

            V[++cnt] = i - (N + 2) + 1;



    return;

}



static inline void Write ()

{

    g << cnt << '\n';

    cnt = min(cnt, 1000);



    for(int i = 1; i <= cnt; ++i)

    {

        g << (--V[i]);



        if(i != cnt)

            g << ' ';

    }



    g << '\n';



    return;

}



int main()

{

    Read();



    Precalculation();



    Solve();



    Write();



    return 0;

}
