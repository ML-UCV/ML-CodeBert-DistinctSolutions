#include <bits/stdc++.h>


using namespace std;



ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");



int n, m, i, p, nr;

int sol[2000005], l[2000005];



char a[2000005], b[2000005];



int main(){

    fin >> a + 1;

    fin >> b + 1;

    n = strlen (a + 1);

    m = strlen (b + 1);

    for (i=2; i<=n; i++){

        while (a[i] != a[p+1] && p != 0){

            p = l[p];

        }

        if (a[i] == a[p+1]){

            p++;

        }

        l[i] = p;

    }

    p = 0;

    for (i=1; i<=m; i++){

        while (b[i] != a[p+1] && p != 0){

            p = l[p];

        }

        if (b[i] == a[p+1]){

            p++;

        }

        if (p == n){

            sol[++nr] = i - p;

            p = l[p];

        }

    }

    fout << nr << "\n";

    nr = min (nr, 1000);

    for (i=1; i<=nr; i++){

        fout << sol[i] << " ";

    }

    return 0;

}
