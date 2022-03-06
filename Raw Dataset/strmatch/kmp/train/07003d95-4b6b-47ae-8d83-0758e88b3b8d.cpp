#include <cstdio>
#include <algorithm>
#include <cstring>


using namespace std;



int n, m, nro;

int o[2000005], P[2000005];

char a[2000005], b[2000005];



void pref()

{

    int i = 1, j = 0;

    P[0] = -1;

    while(i <= n)

    {

        while(j > 0 && a[i] != a[j])

            j = P[j-1] + 1;

        P[i] = j;

        ++i, ++j;

    }
}



void kmp()

{

    int i = 1, j = 1;

    while(i <= m)

    {

        while(j > 0 && b[i] != a[j])

            j = P[j-1]+1;

        ++i, ++j;

        if(j == n+1)

        {

            j = P[j-1]+1;

            nro++;

            if(nro <= 1000)

                o[nro] = i-n-1;

        }

    }

}



void write()

{

    printf("%d\n", nro);

    int vmin = min(nro, 1000);

    for(int i = 1; i <= vmin; ++i)

        printf("%d ", o[i]);

}





int main()

{

    freopen("strmatch.in", "r", stdin);

    freopen("strmatch.out", "w", stdout);

    scanf("%s\n%s", (a+1), (b+1));

    n = strlen(a+1);

    m = strlen(b+1);

    pref();

    kmp();

    write();

    return 0;

}
