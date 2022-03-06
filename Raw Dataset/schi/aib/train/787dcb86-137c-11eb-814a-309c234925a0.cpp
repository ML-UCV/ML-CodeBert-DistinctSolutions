#include <iostream>
#include <fstream>


using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int v[30005], n, conc[30005], aib[30005];



void update(int poz, int val){

    for (int i = poz; i <= n; i += i & (-i))

        aib[i] += val;

}



int cauta(int val){

    int poz = 0;

    for (int i = 1 << 15; i > 0; i >>= 1)

        if ((poz | i) <= n && aib[poz | i] <= val){

            poz |= i;

            val -= aib[poz];

        }

    return poz;

}



int main(){

    fin >> n;

    for (int i = 1; i <= n; i++){

        fin >> v[i];

        update(i, 1);

    }

    for (int i = n; i >= 1; i--){

        int poz = cauta(v[i] - 1) + 1;

        update(poz, -1);

        conc[poz] = i;

    }

    for (int i = 1; i <= n; i++)

        fout << conc[i] << '\n';

    return 0;

}
