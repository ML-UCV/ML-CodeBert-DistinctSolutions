#include <stdio.h>


using namespace std;



void actualizeaza(int start, int b, int n, int *AIB) {

    for (int i = start; i <= n; i += i & (-i))

        AIB[i] += b;

}



int interogheaza(int start, int *AIB) {

    int suma = 0;

    while (start > 0) {

        suma += AIB[start];

        start -= start & (-start);

    }

    return suma;

}



void prelucreaza(int pos, int ind, int *AIB, int *finish, int n) {

    int left = 1, right = n, mid, q, sol;

    while (left <= right) {

        mid = left + (right - left) / 2;

        q = interogheaza(mid, AIB);

        if (mid - q == pos) {

            sol = mid;

            right = mid - 1;

            continue;

        }

        if (mid - q > pos)

            right = mid - 1;

        else

            left = mid + 1;

    }

    actualizeaza(sol, 1, n, AIB);

    finish[sol] = ind;

}



int main() {

 freopen("schi.in", "r", stdin);

 freopen("schi.out", "w", stdout);

 int n;

 scanf("%d", &n);

    int A[n + 1], AIB[n + 1] = {0}, finish[n + 1] = {0};

    for (int i = 1; i <= n; i++)

        scanf("%d", &A[i]);

    for (int i = n; i >= 1; i--) {

        prelucreaza(A[i], i, AIB, finish, n);

    }

    for (int i = 1; i <= n; i++)

        printf("%d\n", finish[i]);

 return 0;

}
