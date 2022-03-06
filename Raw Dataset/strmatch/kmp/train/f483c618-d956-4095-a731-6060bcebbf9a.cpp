#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>


using namespace std;



int solCnt;

int n, m;

int pos[1005], lps[2000005];

char pat[2000005], txt[2000005];
void computeLPSArray(char* pat, int M, int* lps)

{



    int cnd = 0;

    int pos = 1;



    lps[0] = -1;

    while (pos < M) {

        if (pat[pos] == pat[cnd]) {

            lps[pos] = lps[cnd];

        }

        else

        {

            lps[pos] = cnd;

            cnd = lps[cnd];

            while (cnd >= 0 && pat[pos] != pat[cnd])

                cnd = lps[cnd];

        }

        pos++;

        cnd++;

    }

    lps[pos] = cnd;

}



void KMPSearch(char* pat, char* txt)

{

    m = strlen(pat);

    n = strlen(txt);





    computeLPSArray(pat, m, lps);



    int i = 0;

    int j = 0;

    while (i < n) {

        if (pat[j] == txt[i]) {

            j++;

            i++;

            if (j == m) {

                if (solCnt < 1000)

                    pos[solCnt++] = i - j;

                else

                    solCnt++;

                j = lps[j];

            }

        }

        else {

            j = lps[j];

            if (j < 0)

            {

                j++;

                i++;

            }

        }

    }

}





int main()

{

    freopen("strmatch.in", "r", stdin);

    freopen("strmatch.out", "w", stdout);



    scanf("%s", pat);

    scanf("%s", txt);



    KMPSearch(pat, txt);



    printf("%d\n", solCnt);

    for (int i = 0; i < std::min(solCnt, 1000); ++i)

        printf("%d ", pos[i]);

    return 0;

}
