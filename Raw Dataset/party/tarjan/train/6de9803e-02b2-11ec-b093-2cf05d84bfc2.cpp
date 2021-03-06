#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;



typedef struct _clause {

    int x, y, type;

} Clause;



const int MAX_N = 102;

const int MAX_M = 1002;



int n, m;



Clause clause[MAX_M];

bool assign[MAX_N];



void solve() {

    bool done = false;

    int r;



    while (!done) {

        done = true;

        for (int i = 1; i <= m; ++i) {

            if (clause[i].type == 0) {



                if (!assign[clause[i].x] && !assign[clause[i].y]) {

                    r = rand() % 2;

                    if (r) assign[clause[i].x] = true;

                    else assign[clause[i].y] = true;

                    done = false;

                }

            } else if (clause[i].type == 1) {





                if (!assign[clause[i].x] && assign[clause[i].y]) {

                    assign[clause[i].y] = false;

                    done = false;

                }

            } else if (clause[i].type == 2) {





                if (assign[clause[i].x] && !assign[clause[i].y]) {

                    assign[clause[i].x] = false;

                    done = false;

                }

            } else if (clause[i].type == 2) {



                if (assign[clause[i].x] && assign[clause[i].y]) {

                    rand() % 2 ? assign[clause[i].x] = false

                            : assign[clause[i].y] = false;

                    done = false;

                }

            }

        }

    }

}



int main(int argc, char** argv) {

    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);



    srand(time(NULL));





    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++) {

        scanf("%d %d %d", &clause[i].x, &clause[i].y, &clause[i].type);

    }

    for (int i = 1; i <= n; ++i) assign[i] = rand() % 2;



    solve();

    int vars = 0;

    for (int i = 1; i <= n; ++i) {

        if (assign[i]) {

            vars++;

        }

    }



    printf("%d\n", vars);

    for (int i = 1; i <= n; ++i) {

        if (assign[i]) {

            printf("%d\n", i);

        }

    }

    return 0;

}
