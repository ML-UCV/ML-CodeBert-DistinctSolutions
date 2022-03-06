#include <fstream>


using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");



int inv = 0;



int aux[100001];



void interclasare(int v[], int st, int dr) {

    int mij, i, j, k;

    mij = (st + dr) / 2;

    k = 0;

    i = st;

    j = mij + 1;

    while (i <= mij && j <= dr) {

        if (v[i] <= v[j]) aux[++k] = v[i++];

        else {

            aux[++k] = v[j++];

            inv = inv + mij - i + 1;

            inv = inv % 9917;

        }

    }

    while (i <= mij)

        aux[++k] = v[i++];



    while (j <= dr)

        aux[++k] = v[j++];



    for (i = st, j = 1; i <= dr; i++, j++)

        v[i] = aux[j];

}





void mergeSort(int v[], int st, int dr) {

    if (st < dr) {

        int mij = (st + dr) / 2;

        mergeSort(v, st, mij);

        mergeSort(v, mij + 1, dr);

        interclasare(v, st, dr);

    }

}



int main() {



    int v[100001];

    int n, i;

    f>> n;



    for (i = 1; i <= n; ++i)

        f>> v[i];



    mergeSort(v, 1, n);



    g << inv % 9917;



    f.close();

    g.close();



    return 0;

}
