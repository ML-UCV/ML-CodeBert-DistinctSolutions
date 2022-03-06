#include <cstdio>
#include <vector>
#include <deque>
#include <cstring>


using namespace std;



typedef long long LL;



const int kMaxN = 50005;



deque<int> C[2][26];

int N, P[kMaxN], BIT[kMaxN], I;

char S[2][kMaxN];



void BuildP()

{

    for (int i = 1; i <= N; ++i)

        for (int s = 0; s < 2; ++s)

            C[s][S[s][i]-'a'].push_back(i);

    for (int c = 0; c < 26; ++c)

        for (; !C[0][c].empty(); C[0][c].pop_front(), C[1][c].pop_front())

            P[C[0][c].front()] = C[1][c].front();

}



bool CheckS()

{

    vector<int> F(26, 0);

    for (int i = 1; i <= N; ++i)

        ++F[S[0][i]-'a'], --F[S[1][i]-'a'];

    for (int c = 0; c < 26; ++c)

        if (F[c] != 0) return false;

    return true;

}



inline int LSB(const int X)

{

    return X&(-X);

}



inline void Update(int X, const int V)

{

    for (; X <= N; X += LSB(X)) BIT[X] += V;

}



inline int Query(int X)

{

    int Q = 0;

    for (; X; X -= LSB(X)) Q += BIT[X];

    return Q;

}



void Solve()

{

    if (!CheckS())

    {

        I = -1; return;

    }

    BuildP();

    for (int i = 1; i <= N; ++i)

        I += Query(N) - Query(P[i]), Update (P[i], 1);

}



void Read()

{

    freopen("swap.in", "r", stdin);

    scanf("%s\n%s", S[0]+1, S[1]+1);

    N = strlen (S[0]+1);

}



void Print()

{

    freopen("swap.out", "w", stdout);

    printf("%d\n", I);

}



int main()

{

    Read();

    Solve();

    Print();

    return 0;

}
