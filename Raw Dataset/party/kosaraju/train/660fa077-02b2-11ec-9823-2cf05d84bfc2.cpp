#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;



const int NMAX = 210;



int N, M, X, Y, Type, Value[NMAX], Stack[NMAX], Top;

bool Used[NMAX];

vector<int> G[NMAX], GT[NMAX];



int Neg(int X)

{

    if(X <= N) return X + N;

    return X - N;

}



void DFP(int Node)

{

    Used[Node] = 1;

    for(auto it : G[Node])

        if(!Used[it])

            DFP(it);

    Stack[++Top] = Node;

}



void DFM(int Node)

{

    Used[Node] = 1;

    Value[Neg(Node)] = 1;



    for(auto it : GT[Node])

        if(!Used[it])

            DFM(it);

}



void AddEdge(int A, int B)

{

    G[Neg(A)].push_back(B);

    G[Neg(B)].push_back(A);

    GT[A].push_back(Neg(B));

    GT[B].push_back(Neg(A));

}



int main()

{

    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);



    scanf("%i %i", &N, &M);

    for(int i = 1; i <= M; ++ i)

    {

        scanf("%i %i %i", &X, &Y, &Type);

        if(Type == 0) AddEdge(X, Y);

        else if(Type == 1) AddEdge(X, Neg(Y));

        else if(Type == 2) AddEdge(Neg(X), Y);

        else AddEdge(Neg(X), Neg(Y));

    }



    for(int i = 1; i <= N; ++ i)

        if(!Used[i])

            DFP(i);



    memset(Used, 0, sizeof(Used));



    for(int i = Top; i; -- i)

        if(!Used[ Stack[i] ] && !Used[ Neg(Stack[i]) ])

            DFM(Stack[i]);



    int Cnt = 0;

    for(int i = 1; i <= N; ++ i)

        Cnt += Value[i];



    printf("%i\n", Cnt);

    for(int i = 1; i <= N; ++ i)

        if(Value[i])

            printf("%i\n", i);

}
