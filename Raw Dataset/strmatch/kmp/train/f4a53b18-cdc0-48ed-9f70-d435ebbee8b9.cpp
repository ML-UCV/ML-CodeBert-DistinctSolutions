#include <fstream>
#include <cstring>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



int n, m, i, p[2000002], L, nr, sol[1200];

char a[2000002], b[2000002];



int main(){

    fin>>(a+1);

    L = 0;

    p[1] = 0;

    n = strlen(a+1);

    for(i=2;i<=n;i++){

        while(a[L+1] != a[i] && L)

            L = p[L];

        if(a[L+1] == a[i])

            L++;

        p[i] = L;

    }

    fin>>(b+1);

    m = strlen(b+1);

    L = 0;

    for(i=1;i<=m;i++){

        while(a[L+1] != b[i] && L)

            L = p[L];

        if(a[L+1] == b[i])

            L++;

        if(L == n){

            nr++;

            if(nr <= 1000)

                sol[nr] = i-n;

        }

    }

    fout<<nr<<"\n";

    if(nr > 1000)

        nr = 1000;

    for(i=1;i<=nr;i++)

        fout<<sol[i]<<" ";

    return 0;

}
