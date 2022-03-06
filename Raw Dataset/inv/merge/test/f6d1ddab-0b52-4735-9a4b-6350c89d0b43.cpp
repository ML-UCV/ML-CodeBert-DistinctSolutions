#include <iostream>
#include <fstream>
using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");



const int NMAX = 100001;

long long nr_inv;



void interclasare(int v[], int p, int u, int m)

{

    int a[NMAX];

    int i = p, j = m + 1, k = 1, mij = (p + u)/2;

    while(i <= m && j <= u)

        if(v[i] <= v[j])

            a[k++] = v[i++];

        else

        {

            a[k++] = v[j++];

            nr_inv += (mij - i + 1)%9917;

        }

    while(i <= m) a[k++] = v[i++];

    while(j <= u) a[k++] = v[j++];

    for(i = p, k = 1; i <= u; i++, k++)

        v[i] = a[k];

}



void merge_sort(int v[], int p, int u)

{

    if(p < u)

    {

        int m = (p + u)/2;

        merge_sort(v, p, m);

        merge_sort(v, m + 1, u);

        interclasare(v, p, u, m);

    }

}



int main()

{

    int s[NMAX], n;

    f >> n;

    for(int i = 1; i <= n; i++)

        f >> s[i];



    merge_sort(s, 1, n);

    g << nr_inv % 9917;

    return 0;

}
