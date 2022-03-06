#include <iostream>
#include <stdio.h>


using namespace std;



const int NMAX = 250005;

int t[20][NMAX];



int main() {



    freopen ("stramosi.in", "r", stdin);

    freopen ("stramosi.out", "w", stdout);



    int n, teste, i, q, p, j, w;



    scanf ("%d%d", &n, &teste);

    for (i = 1; i <= n; i++)

        scanf ("%d", &t[0][i]);



    for (i = 1; 1 << i <= n; i++) {

        for (j = 1; j <= n; j++)

            t[i][j] = t[i - 1][t[i - 1][j]];

    }



    for (w = 1; w <= teste; w++) {

        scanf ("%d%d", &q, &p);

        for (i = 0; i <= 17; i++)

            if (((1 << i) & p) != 0) {

                q = t[i][q];

            }

        printf ("%d\n", q);



    }



    return 0;

}
