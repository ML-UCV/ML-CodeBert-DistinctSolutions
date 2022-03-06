#include <iostream>
#include <fstream>


using namespace std;



const int maxN = 100001,

          MOD = 9917;



int a[maxN], b[maxN];



ifstream in("inv.in");

ofstream out("inv.out");



int interClas(int p, int q, int m) {

    int i = p,

        j = m+1,

        k = 0,

        inv = 0;

    while(i <= m && j <= q)

        if(a[i] <= a[j])

            b[++k] = a[i++];

        else {

            b[++k] = a[j++];

            inv = (inv+m-i+1)%MOD;

        }

    while(i <= m)

        b[++k] = a[i++];

    while(j <= q)

        b[++k] = a[j++];

    k = 1;

    for(int i = p; i <= q; i++)

        a[i] = b[k++];

    return inv;

}



int mergeSort(int p, int q) {

    int inv = 0;

    if(p < q) {

        int m = (p+q)/2;

        inv = mergeSort(p, m)%MOD;

        inv = (inv+mergeSort(m+1, q))%MOD;

        inv = (inv+interClas(p, q, m))%MOD;

    }

    return inv%MOD;

}



int main()

{

    int n;

    in >> n;

    for(int i = 1; i <= n; i++)

        in >> a[i];



    out << mergeSort(1, n);

    return 0;

}
