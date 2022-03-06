#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;



typedef pair<int, int> pii;

typedef long long int ll;



int n, m, len;

int z[2 * 2000010];

char a[2000010], b[2000010], c[2 * 2000010];



int main()

{

    freopen("strmatch.in", "r", stdin);

    freopen("strmatch.out", "w", stdout);



    scanf("%s", a + 1);

    scanf("%s", b + 1);



    int n = strlen(a + 1);

    int m = strlen(b + 1);



    len = n;



    for (int i = 1; i <= n; i++) c[i] = a[i];



    c[++len] = '@';



    for (int i = 1; i <= m; i++) c[++len] = b[i];



    z[1] = 0;

    int l = 0, r = 0;



    for (int i = 2; i <= len; i++) {



        if (i > r) {



            l = r = i;



            while (r <= len && c[r] == c[r - l + 1]) r++;



            z[i] = r - l; r--;

        }

        else

        {

            int pos = i - l + 1;



            if (i + z[pos] <= r) z[i] = z[pos]; else

            {

                l = i;



                while (r <= len && c[r] == c[r - l + 1]) r++;



                z[i] = r - l; r--;

            }

        }

    }



    vector <int> vc;



    for (int i = n + 1; i <= len; i++)

        if (z[i] == n) vc.push_back(i - n - 2);



    printf("%d\n", ((int)(vc.size())));



    for (int i = 0; i < min(((int)(vc.size())), 1000); i++) printf("%d ", vc[i]);
    return 0;

}
