#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>


std::ifstream fin("party.in");

std::ofstream fout("party.out");







const int MAXN = 110;

const int MAXM = 1100;



int n, m, sol[MAXN], expresie[MAXM][2];



void read() {

    fin >> n >> m;



    for (int (i) = (1); (i) <= (m); ++(i)) {

        int type;

        fin >> expresie[i][0] >> expresie[i][1] >> type;



        if (type == 1 || type == 3) expresie[i][1] = -expresie[i][1];

        if (type == 2 || type == 3) expresie[i][0] = -expresie[i][0];

    }

}



int abs(int a) {

    if (a < 0)

        return -a;

    return a;

}



bool eval(int a, int b) {

    int x, y;



    x = sol[abs(a)];

    y = sol[abs(b)];



    if (a < 0) x ^= 1;

    if (b < 0) y ^= 1;



    return x | y;

}



void solve() {

    srand(time(0));

    for (int (i) = (1); (i) <= (n); ++(i))

        sol[i] = rand() % 2;



    for(;;) {

        int poz = 0;

        for (int (i) = (1); (i) <= (m); ++(i)) {

            if (!eval(expresie[i][0], expresie[i][1])) {

                poz = i;

                break;

            }

        }

        if (!poz) break;

        if ((rand() % 2) == 0)

            sol[abs(expresie[poz][0])] ^= 1;

        else

            sol[abs(expresie[poz][1])] ^= 1;

    }

}



void print() {

    int sum = 0;

    for (int (i) = (1); (i) <= (n); ++(i))

        sum += sol[i];



    fout << sum << "\n";



    for (int (i) = (1); (i) <= (n); ++(i))

        if (sol[i])

            fout << i << "\n";

}



int main() {

    read();

    solve();

    print();

    return 0;

}
