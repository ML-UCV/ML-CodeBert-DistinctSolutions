#include <stdio.h>
#include <vector>
#include <string.h>


using namespace std;







char A[2000001], B[2000001];



int lps[2000001];



void computeLPSArray(char* pat, int M, int lps[])

{

    int len = 0;

    lps[0] = 0;



    int i = 1;



    while (i < M)

    {

        if (pat[i] == pat[len])

        {

            len++;

            lps[i] = len;

            i++;

        }

        else

        {

            if (len != 0)

            {

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



int main()

{

    freopen("strmatch.in", "rt", stdin);

    freopen("strmatch.out", "wt", stdout);

    scanf("%s %s", A, B);

    int nr = 0;

    vector <int> sir;

    int M = strlen(A);

    int N = strlen(B);

    computeLPSArray(A, M, lps);
    if (M > N)

    {

        printf("0\n");

        return 0;

    }



    int j = 0;

    int i = 0;

    while (i < N)

    {

        if (A[j] == B[i])

        {

            j++;

            i++;

        }

        if (j == M && j != 0)

        {

            j = lps[j - 1];

            sir.push_back(i - M);

            nr++;

        }

        else if (i < N && A[j] != B[i])

        {

            if (j != 0)

                j = lps[j - 1];

            else

                i++;

        }

    }

    printf("%d\n", nr);

    for (int i = 0; i < ((sir.size() < 1000) ? sir.size() : 1000); i++)

    {

        printf("%d ", sir[i]);

    }

    return 0;

}
