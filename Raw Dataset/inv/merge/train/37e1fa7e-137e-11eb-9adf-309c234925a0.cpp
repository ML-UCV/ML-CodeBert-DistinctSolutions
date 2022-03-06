#include <iostream>
#include <fstream>
using namespace std;

ifstream in("inv.in");

ofstream out("inv.out");

int nr = 0;

void interclasare(int v[], int aux[], int st, int m, int dr) {

    int i, j, k;

    i = st;

    j = m;

    k = st;

    while ((i<=m-1)&&(j<=dr)) {

        if (v[i]<=v[j])

            aux[k++]=v[i++];

        else{

            aux[k++] = v[j++];

            nr += (m-i);

            nr = nr%9917;

        }

    }

    while (i<=m-1)

        aux[k++] = v[i++];

    while (j<=dr)

        aux[k++] = v[j++];

    for (i=st;i<=dr;i++)

        v[i] = aux[i];

}



void mergeSort(int v[], int aux[], int st, int dr) {

    int m;

    if (dr>st){

        m = (dr+st)/2;

        mergeSort(v, aux, st, m);

        mergeSort(v, aux, m+1, dr);

        interclasare(v, aux, st, m+1, dr);

    }

}





int main() {

    int v[100005],n,aux[100005];

    in>>n;

    for(int i=0;i<n;i++)

        in>>v[i];

    mergeSort(v, aux, 0, n-1);

    out<<nr;

}
