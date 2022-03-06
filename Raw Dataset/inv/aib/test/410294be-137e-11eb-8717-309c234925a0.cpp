#include <bits/stdc++.h>






template <int MAXN> class Normalize {

private:

    int value[MAXN];



public:

    Normalize(int N, int V[]) {

        std::vector <int> normSet;

        for (int i=0; i<N; ++i)

            normSet.push_back(V[i]);

        std::sort(normSet.begin(), normSet.end());

        for (int i=0; i<N; ++i)

            value[i] = std::lower_bound(normSet.begin(), normSet.end(), V[i]) - normSet.begin() + 1;

    }



    int operator[] (int idx) {return value[idx];}

};







int N, AIB[4*100005];

int V[100005];







void updateAIB(int X) {

    for (X; X<=N; X+=(X&(-X)))

        ++ AIB[X], AIB[X] %= 9917;

}



int queryAIB(int X) {

    int ans = 0;

    for (X; X>=1; X-=(X&(-X)))

        ans += AIB[X], ans %= 9917;

    return ans;

}



std::ifstream input ("inv.in");

std::ofstream output("inv.out");



void readInput() {

    input >> N;

    for (int i=1; i<=N; ++i)

        input >> V[i];

}



void solveInput() {

    Normalize <100005> normVal(N, V+1);

    int ans = 0;

    for (int i=0; i<N; ++i)

        ans += queryAIB(N) - queryAIB(normVal[i]), updateAIB(normVal[i]),

        ans += 9917, ans %= 9917;

    output << ans << '\n';

}



int main()

{

    readInput();

    solveInput();



    return 0;

}
