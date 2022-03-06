#include <bits/stdc++.h>


using namespace std;



ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");



int i, j, n, m, cnt;

int p[2000005], sol[2000005];



char a[2000005], b[2000005];



int main(){

    fin >> a + 1;

    fin >> b + 1;

    n = strlen (a + 1), m = strlen (b + 1);

    for (i=2; i<=n; i++){

        while (j > 0 && a[j+1] != a[i]){

            j = p[j];

        }

        if (a[j+1] == a[i]){

            j++;

        }

        p[i] = j;

    }

    j = 0;

    for (i=1; i<=m; i++){

        while (j > 0 && a[j+1] != b[i]){

            j = p[j];

        }

        if (a[j+1] == b[i]){

            j++;

        }

        if (j == n){

            sol[++cnt] = i - j;

            j = p[j];

        }

    }

    fout << cnt << "\n";

    cnt = min (cnt, 1000);

    for (i=1; i<=cnt; i++){

        fout << sol[i] << " ";

    }

    return 0;

}
