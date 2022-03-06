#include <bits/stdc++.h>


using namespace std;



ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");



char a[2000005], b[2000005];



int n, m, i, j, cnt;

int sol[2000005], l[2000005];



int main(){

    fin >> a + 1;

    fin >> b + 1;

    n = strlen (a + 1);

    m = strlen (b + 1);

    for (i=2; i<=n; i++){

        while (a[i] != a[j+1] && j){

            j = l[j];

        }

        if (a[i] == a[j+1]){

            j++;

        }

        l[i] = j;

    }

    j = 0;

    for (i=1; i<=m; i++){

        while (b[i] != a[j+1] && j){

            j = l[j];

        }

        if (b[i] == a[j+1]){

            j++;

        }

        if (j == n){



            sol[++cnt] = i - n;

            j = l[j];

        }

    }

    fout << cnt << "\n";

    cnt = min (cnt, 1000);

    for (i=1; i<=cnt; i++){

        fout << sol[i] << " ";

    }

    return 0;

}
