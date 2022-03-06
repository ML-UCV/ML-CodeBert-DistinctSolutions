#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;



char A[2000001], B[2000001];
int main()

{

    vector<int> result;



    freopen("strmatch.in", "rt", stdin);

    freopen("strmatch.out", "wt", stdout);

    scanf("%s %s", A, B);



    int M = strlen(A);

    int N = strlen(B);







    int p = 1, p2 = 1, n = 0;

    int aVal = 0;

    int aVal2 = 0;



    if (M > N)

    {

        printf("0\n");

        return 0;

    }



    int hash1 = 0;

    int hash2 = 0;



    for (int i = 0; i < M; i++)

    {

        aVal = (aVal * 73 + A[i]) % 100007;

        aVal2 = (aVal2 * 73 + A[i]) % 100011;

        hash1 = (hash1 * 73 + B[i]) % 100007;

        hash2 = (hash2 * 73 + B[i]) % 100011;

        if (i != 0)

        {

            p = (p * 73) % 100007;

            p2 = (p2 * 73) % 100011;

        }

    }



    if (hash1 == aVal && hash2 == aVal2)

    {

        n++;

        result.push_back(0);

    }



    for (int i = M; i < N; i++)

    {

        hash1 = ((hash1 - (B[i - M] * p) % 100007 + 100007) * 73 + B[i]) % 100007;

        hash2 = ((hash2 - (B[i - M] * p2) % 100011 + 100011) * 73 + B[i]) % 100011;

        if (hash1 == aVal && hash2 == aVal2)

        {

            if(n < 1000)

                result.push_back(i - M + 1);

            n++;

        }

    }



    printf("%d\n", n);

    for (int i = 0; i < result.size(); i++)

    {

        printf("%d ", result[i]);

    }



    return 0;

}
