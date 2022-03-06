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



    int len = 0;



    lps[0] = 0;





    int i = 1;

    while (i < M) {

        if (pat[i] == pat[len]) {

            len++;

            lps[i] = len;

            i++;

        }

        else

        {







            if (len != 0) {

                len = lps[len - 1];







            }

            else

            {

                lps[i] = 0;

                i++;

            }

        }

    }

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

        }



        if (j == m) {

            if (solCnt < 1000)

                pos[solCnt++] = i - j;

            else

                solCnt++;

            j = lps[j - 1];

        }





        else if (i < n && pat[j] != txt[i]) {





            if (j != 0)

                j = lps[j - 1];

            else

                i = i + 1;

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
