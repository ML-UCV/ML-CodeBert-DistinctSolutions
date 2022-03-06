#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int NMAX = 2000000;

const int MMAX = 2000000;

int urm[MMAX + 5];

char t[NMAX + 5] , p[MMAX + 5];

vector <int> ans;

int main()

{

    freopen("strmatch.in" , "r" , stdin);

    freopen("strmatch.out" , "w" , stdout);

    int n , m , i , k , nr;

    scanf("%s\n%s" , (p + 1) , (t + 1));

    n = strlen(t + 1);

    m = strlen(p + 1);

    k = 0;

    urm[1] = 0;

    for(i = 2 ; i <= m ; i ++)

    {

        while(k > 0 && p[k + 1] != p[i])

            k = urm[k];

        if(p[k + 1] == p[i])

            k ++;

        urm[i] = k;

    }

    k = nr = 0;

    for(i = 1 ; i <= n ; i ++)

    {

        while(k > 0 && p[k + 1] != t[i])

            k = urm[k];

        if(p[k + 1] == t[i])

            k ++;

        if(k == m)

        {

            nr ++;

            if(ans.size() < 1000)

                ans.push_back(i - m);

            k = urm[k];

        }

    }

    printf("%d\n" , nr);

    for(i = 0 ; i < ans.size() ; i ++)

        printf("%d " , ans[i]);

    return 0;

}
