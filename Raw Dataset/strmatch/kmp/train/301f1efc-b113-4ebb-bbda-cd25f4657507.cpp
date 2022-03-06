#include <cstdio>
#include <cstring>
using namespace std;



char A[2000005], B[2000005];

int prefix[2000005], sol[1005];



int main() {

    int lenA, lenB, i, j, n = 0;

    freopen("strmatch.in", "r", stdin);

    freopen("strmatch.out", "w", stdout);



    scanf("%s%s", A, B);

    lenA = strlen(A);

    lenB = strlen(B);



    for(i = lenA; i >= 1; --i)

        A[i] = A[i-1];

    for(i = lenB; i >= 1; --i)

        B[i] = B[i-1];



    for(i = 2, j = 0; i <= lenA; ++i) {

        while(j && A[i] != A[j+1])

            j = prefix[j];

        if(A[i] == A[j+1])

            ++j;

        prefix[i] = j;

    }



    for(i = 1, j = 0; i <= lenB; ++i) {

        while(j && B[i] != A[j+1])

            j = prefix[j];

        if(B[i] == A[j+1])

            ++j;

        if(j == lenA) {

            j = prefix[j];

            ++n;

            if(n <= 1000)

                sol[n] = i - lenA;

        }

    }



    printf("%d\n", n);

    n = (n < 1000 ? n : 1000);

    for(i = 1; i <= n; ++i)

        printf("%d ", sol[i]);

    printf("\n");

}
