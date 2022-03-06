#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int NMAX = 5000005;

char s[NMAX];

int z[NMAX];

vector <int> sol;



int main() {

    freopen("strmatch.in", "r", stdin);

    freopen("strmatch.out", "w", stdout);

    scanf("%s", s + 1);

    int n = (int)strlen(s + 1);

    s[n + 1] = '#';

    scanf("%s", s + n + 2);

    int m = (int)strlen(s + 1);

    int st = 1, dr = 1;

    z[1] = 1;

    for(int k = 2; k <= m; k++) {

        if(s[k] != s[1]) {

            z[k] = 0;

        }

        else {

            int poz = k;

            if(k <= dr) {

                poz = min(dr, k + z[k - st + 1] - 1);

            }

            while(poz <= m && s[poz] == s[poz - k + 1]) {

                poz++;

            }

            poz--;

            if(dr < poz) {

                dr = poz;

                st = k;

            }

            z[k] = poz - k + 1;

        }

    }

    for(int k = n + 1; k <= m; k++) {

        if(z[k] == n) {

            sol.push_back(k - n);

        }

    }

    printf("%d\n", sol.size());

    for(int i = 0; i < sol.size() && i < 1000; i++) {

        printf("%d ", sol[i] - 2);

    }

    return 0;

}
