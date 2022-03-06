#include <bits/stdc++.h>


using namespace std;



struct muchie{int n1, n2, cost;};



const int NMAX = 200005;

const int MMAX = 400005;



int sef[NMAX];

muchie vm[MMAX], sol[NMAX];



bool cmp(muchie a, muchie b) {

    return a.cost < b.cost;

}



int sefsuprem (int x) {

    if (sef[x] == x)

        return x;

    else

        return sef[x] = sefsuprem(sef[x]);

}



void unire(int x, int y) {

    int sefx = sefsuprem(x);

    int sefy = sefsuprem(y);

    sef[sefx] = sefy;

}



int main() {



    freopen ("apm.in", "r", stdin);

    freopen ("apm.out", "w", stdout);



    int n, m, i, adaug, sum;



    scanf ("%d%d", &n, &m);



    for (i = 1; i <= m; i++)

        scanf ("%d%d%d", &vm[i].n1, &vm[i].n2, &vm[i].cost);



    sort(vm + 1, vm + m + 1, cmp);



    for (i = 1; i <= n; i++)

        sef[i] = i;



    adaug = 0;

    i = 1;

    sum = 0;

    while (adaug < n - 1) {

        if (sefsuprem(vm[i].n1) != sefsuprem(vm[i].n2)) {



            unire(vm[i].n1, vm[i].n2);

            sum += vm[i].cost;

            adaug++;

            sol[adaug].n1 = vm[i].n1;

            sol[adaug].n2 = vm[i].n2;

        }

        i++;

    }

    printf ("%d\n%d\n", sum, adaug);

    for (i = 1; i <= adaug; i++)

        printf ("%d %d\n", sol[i].n1, sol[i].n2);







    return 0;

}
