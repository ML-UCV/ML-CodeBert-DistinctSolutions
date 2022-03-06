#include <iostream>
#include <stdio.h>


using namespace std;



const int NMAX = 100005;

int sol[NMAX], s[NMAX], v[NMAX];

int n;



int len(int x) {

    return (x - (x & (x - 1)));

}



void update(int pz, int val) {

    while (pz <= n) {

        s[pz] += val;

        pz += len(pz);

    }

}



int main() {



    freopen ("schi.in", "r", stdin);

    freopen ("schi.out", "w", stdout);



    int i, rz, pas, x;



    scanf ("%d", &n);

    for (i = 1; i <= n; i++) {

        scanf ("%d", &v[i]);

        update(i, 1);

    }



    for (i = n; i >= 1; i--) {

        x = v[i];

        pas = (1 << 20);

        rz = 0;

        while (pas > 0) {

            if (rz + pas <= n && s[rz + pas] < x) {

                rz += pas;

                x -= s[rz];

            }

            pas /= 2;

        }

        rz++;

        sol[rz] = i;

        update(rz, -1);

    }



    for (i = 1; i <= n; i++)

        printf ("%d\n", sol[i]);



    return 0;

}
