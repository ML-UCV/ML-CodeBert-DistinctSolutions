#include <cstdio>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;



int N, M;

pair <int, int> EXPR[100100];

int SOL[100100];



bool eval_term(pair <int, int> T) {

    int x, y;



    x = SOL[abs(T.first)];

    y = SOL[abs(T.second)];



    if (T.first < 0)

        x ^= 1;

    if (T.second < 0)

        y ^= 1;



    return (x | y);

}



void print_sol() {

    int i;

    for (i = 1; i <= N; i++)

        printf("%d ", SOL[i]);

}





void read() {

    int i, a, b, c;

    scanf("%d%d", &N, &M);

    for (i = 1; i <= M; i++) {

        scanf("%d%d%d", &a, &b, &c);

        if (c == 0)

            EXPR[i] = make_pair(a, b);

        if (c == 1)

            EXPR[i] = make_pair(a, -b);

        if (c == 2)

            EXPR[i] = make_pair(-a, b);

        if (c == 3)

            EXPR[i] = make_pair(-a, -b);

    }



}



void afis() {

    int i, rez = 0;

    for (i = 1; i <= N; i++)

        rez += SOL[i];



    printf("%d\n", rez);

    for (i = 1; i <= N; i++)

        if (SOL[i] == 1)

            printf("%d\n", i);

}



int main() {



    int i, a, b, P;



    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);



    read();
    srand(time(0));



    for (i = 1; i <= N; i++)

        SOL[i] = rand() % 2;



    for (int step = 0; step <= N * N * 6; step++) {

        int curr_res = 1;

        for (i = 1; i <= M; i++) {

            curr_res &= eval_term(EXPR[i]);

            if (curr_res == 0) {

                P = i;

                break;

            }

        }



        if (curr_res == 1) {

            afis();



            return 0;

        }



        if (rand() % 2 == 0)

            SOL[abs(EXPR[P].first)] ^= 1;

        else

            SOL[abs(EXPR[P].second)] ^= 1;

    }



    printf("-1\n");



    return 0;

}
