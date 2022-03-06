#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>


using namespace std;



typedef vector<int>::iterator vii;



const int MaxN = 205;



vector<int> G[MaxN], GT[MaxN];

int N, graph[MaxN];

bool fol[MaxN], values[MaxN], solutie;



void df_Trav(int X) {

    fol[X] = X;

    for (vii Y = G[X].begin(); Y != G[X].end(); ++Y)

        if (!fol[*Y])

            df_Trav(*Y);

    graph[++graph[0]] = X;

}

inline int Non(int X) {

    return X > N ? X - N : X + N;

}


void df_Dir(int X) {

    if (values[X])

        solutie = false;

    values[X] = false, values[Non(X)] = true;

    fol[X] = false;

    for (vii Y = GT[X].begin(); Y != GT[X].end(); ++Y)

        if (fol[*Y])

            df_Dir(*Y);

}



void Solve2Sat() {

    solutie = true;

    for (int X = 1; X <= 2 * N; ++X)

        if (!fol[X])

            df_Trav(X);

    reverse(graph + 1, graph + graph[0] + 1);

    for (int i = 1; i <= graph[0]; ++i) {

        int X = graph[i];

        if (fol[X] && fol[Non(X)])

            df_Dir(X);

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

        NTrue += values[X];

    printf("%d\n", NTrue);

    for (int X = 1; X <= N; ++X)

        if (values[X])

            printf("%d\n", X);

}



int main() {

    Read();

    Solve2Sat();

    Print();

    return 0;

}
