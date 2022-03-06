#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;



const int NMAX = 50005, ALPHA = 26;



int N, FreqA[ALPHA], FreqB[ALPHA], FT[NMAX], Ptr[ALPHA], Ans;

vector<int> Pos[ALPHA];

char A[NMAX], B[NMAX];



int LSB(int X)

{

    return ((X & (X - 1)) ^ X);

}



void Update(int Pos)

{

    for(; Pos <= N; Pos += LSB(Pos))

        FT[Pos] ++;

}



int Ask(int Pos)

{

    int Ans = 0;

    for(; Pos; Pos -= LSB(Pos))

        Ans += FT[Pos];

    return Ans;

}



int main()

{

    freopen("swap.in", "r", stdin);

    freopen("swap.out", "w", stdout);



    fgets(A , 50001, stdin);

    fgets(B , 50001, stdin);

    N = strlen(A + 1);



    for(int i = 1; i <= N; ++ i)

    {

        FreqA[A[i] - 'a'] ++;

        FreqB[B[i] - 'a'] ++;

        Pos[A[i] - 'a'].push_back(i);

    }



    for(int i = 0; i < ALPHA; ++ i)

        if(FreqA[i] != FreqB[i])

        {

            printf("-1\n");

            return 0;

        }



    for(int i = 1; i <= N; ++ i)

    {

        int Ch = B[i] - 'a', NextPos = Pos[Ch][ Ptr[Ch] ];

        Ptr[Ch] ++;



        Ans += NextPos - i + Ask(N - NextPos + 1);

        Update(N - NextPos + 1);

    }



    printf("%i\n", Ans);

}
