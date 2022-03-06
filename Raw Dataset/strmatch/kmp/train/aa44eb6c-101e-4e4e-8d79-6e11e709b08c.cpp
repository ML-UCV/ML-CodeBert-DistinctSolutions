#include <fstream>
#include <cstring>


using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



const int NMAX = 2e6 + 5;



const int Base_1 = 131, Mod_1 = 1e9 + 7;

const int Base_2 = 137, Mod_2 = 1e9 + 9;



int N, M;

char A[NMAX], B[NMAX];



int p_1[NMAX], p_2[NMAX];

int H_1, H_2;



int Sol[NMAX];



char Const;



static inline void Read ()

{

    f.tie(nullptr);



    f >> (A + 1) >> (B + 1);



    N = (int)strlen(A + 1), M = (int)strlen(B + 1);



    for(int i = 1; i <= N; ++i)

        Const = min(Const, A[i]);

    for(int i = 1; i <= M; ++i)

        Const = min(Const, B[i]);



    return;

}



static inline void Precalculation ()

{

    p_1[0] = p_2[0] = 1;



    for(int i = 1; i < N; ++i)

    {

        p_1[i] = (1LL * p_1[i - 1] * Base_1) % (1LL * Mod_1);



        p_2[i] = (1LL * p_2[i - 1] * Base_2) % (1LL * Mod_2);

    }



    return;

}



static inline void Find_Key ()

{

    for(int i = 1; i <= N; ++i)

    {

        int Now = (int)(A[i] - Const);



        H_1 = ((1LL * H_1 * Base_1) % (1LL * Mod_1) + Now) % Mod_1;

        H_2 = ((1LL * H_2 * Base_2) % (1LL * Mod_2) + Now) % Mod_2;

    }



    return;

}



auto Ok = [] (int h_1, int h_2)

{

    if(h_1 == H_1 && h_2 == H_2)

        return 1;



    return 0;

};



static inline void Solve ()

{

    int h_1 = 0, h_2 = 0;



    for(int i = 1; i <= N; ++i)

    {

        int Now = (int)(B[i] - Const);



        h_1 = ((1LL * h_1 * Base_1) % (1LL * Mod_1) + Now) % Mod_1;

        h_2 = ((1LL * h_2 * Base_2) % (1LL * Mod_2) + Now) % Mod_2;

    }



    if(Ok(h_1, h_2))

        Sol[++Sol[0]] = 0;



    for(int i = (N + 1); i <= M; ++i)

    {

        int Last = (int)(B[i - N] - Const), Now = (int)(B[i] - Const);



        h_1 = (h_1 - (1LL * Last * p_1[(N - 1)]) % (1LL * Mod_1));

        if(h_1 < 0)

            h_1 += Mod_1;

        h_1 = ((1LL * h_1 * Base_1) % (1LL * Mod_1) + Now) % Mod_1;



        h_2 = (h_2 - (1LL * Last * p_2[(N - 1)]) % (1LL * Mod_2));

        if(h_2 < 0)

            h_2 += Mod_2;

        h_2 = ((1LL * h_2 * Base_2) % (1LL * Mod_2) + Now) % Mod_2;



        if(Ok(h_1, h_2))

            Sol[++Sol[0]] = i - N;

    }



    return;

}



static inline void Write ()

{

    g << Sol[0] << '\n';



    int n = min(Sol[0], 1000);



    for(int i = 1; i <= n; ++i)

    {

        g << Sol[i];



        if(i != n)

            g << ' ';

    }



    g << '\n';



    return;

}



int main()

{

    Read();



    Precalculation();



    Find_Key();



    Solve();



    Write();



    return 0;

}
