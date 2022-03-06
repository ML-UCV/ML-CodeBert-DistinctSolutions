#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;



const int NMAX = 210;



int N, M, X, Y, Z, TopSort[NMAX], Val[NMAX];

bool Used[NMAX];

vector<int> G[NMAX], GT[NMAX];



int Neg(int X)

{

    if(X <= N) return X + N;

    else return X - N;

}



void DFP(int Node)

{

    Used[Node] = 1;

    for(vector<int> :: iterator it = G[Node].begin(); it != G[Node].end(); ++ it)

        if(!Used[*it])

            DFP(*it);

    TopSort[ ++ TopSort[0] ] = Node;

}



void DFM(int Node)

{

    Val[ Neg(Node) ] = 1;

    Used[Node] = 0;



    for(vector<int> :: iterator it = GT[Node].begin(); it != GT[Node].end(); ++ it)

        if(Used[*it])

            DFM(*it);

}



int main()

{

    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);



    scanf("%i %i", &N, &M);

    for(int i = 1; i <= M; ++ i)

    {

        scanf("%i %i %i", &X, &Y, &Z);



        if(Z == 1) Y = Neg(Y);

        else if(Z == 2) X = Neg(X);

        else if(Z == 3) X = Neg(X), Y = Neg(Y);



        G[Neg(Y)].push_back(X);

        GT[X].push_back(Neg(Y));

        G[Neg(X)].push_back(Y);

        GT[Y].push_back(Neg(X));

    }



    for(int i = 1; i <= 2 * N; ++ i)

        if(!Used[i])

            DFP(i);

    reverse(TopSort + 1, TopSort + TopSort[0] + 1);

    for(int i = 1; i <= 2 * N; ++ i)

        if(Used[ TopSort[i] ] && Used[ Neg(TopSort[i]) ])

            DFM(TopSort[i]);



    int Ans = 0;

    for(int i = 1; i <= N; ++ i) Ans += Val[i];



    printf("%i\n", Ans);

    for(int i = 1; i <= N; ++ i)

        if(Val[i])

            printf("%i\n", i);

}
