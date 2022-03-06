#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>


using namespace std;



typedef vector<int>::iterator vii;



const int MaxN = 205;



vector<int> G[MaxN], GT[MaxN];

int N, TSort[MaxN];

bool Used[MaxN], Value[MaxN], Solution;



inline int Non(int X) {

    return X > N ? X - N : X + N;

}



void DFP(int X) {

    Used[X] = true;

    for (vii Y = G[X].begin(); Y != G[X].end(); ++Y)

        if (!Used[*Y])

            DFP(*Y);

    TSort[++TSort[0]] = X;

}



void DFM(int X) {

    if (Value[X])

        Solution = false;

    Value[X] = false, Value[Non(X)] = true;

    Used[X] = false;

    for (vii Y = GT[X].begin(); Y != GT[X].end(); ++Y)

        if (Used[*Y])

            DFM(*Y);

}



void Solve2Sat() {

    Solution = true;

    for (int X = 1; X <= 2 * N; ++X)

        if (!Used[X])

            DFP(X);

    reverse(TSort + 1, TSort + TSort[0] + 1);

    for (int i = 1; i <= TSort[0]; ++i) {

        int X = TSort[i];

        if (Used[X] && Used[Non(X)])

            DFM(X);

    }

}



inline void AddEdge(int X, int Y) {

    G[X].push_back(Y), GT[Y].push_back(X);

}



inline void Disjunction(int X, int Y) {

    AddEdge(Non(X), Y), AddEdge(Non(Y), X);

}



void Read() {

    assert(freopen("party.in", "r", stdin));

    int M; assert(scanf("%d %d", &N, &M) == 2);

    for (; M > 0; --M) {

        int Type, X, Y; assert(scanf("%d %d %d", &X, &Y, &Type) == 3);

        if (Type == 0)

            Disjunction(X, Y);

        if (Type == 1)

            Disjunction(X, Non(Y));

        if (Type == 2)

            Disjunction(Non(X), Y);

        if (Type == 3)

            Disjunction(Non(X), Non(Y));

    }

}



void Print() {

    assert(freopen("party.out", "w", stdout));

    int NTrue = 0;

    for (int X = 1; X <= N; ++X)

        NTrue += Value[X];

    printf("%d\n", NTrue);

    for (int X = 1; X <= N; ++X)

        if (Value[X])

            printf("%d\n", X);

}



int main() {

    Read();

    Solve2Sat();

    Print();

    return 0;

}
