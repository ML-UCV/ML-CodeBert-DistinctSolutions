#include <stdio.h>




using namespace std;



int nr_inversiuni;



void sortare_interclasare(int *v, int *a, int *b, int n) {

    int i = 0, j = 0, mid = n / 2;

    for (int k = 0; k < n; k++) {

        if (i == mid) {

            v[k] = b[j];

            j++;

            continue;

        }

        if (j == mid + n % 2) {

            v[k] = a[i];

            i++;

            continue;

        }

        if (a[i] > b[j]) {

            v[k] = b[j];

            nr_inversiuni = (nr_inversiuni + mid - i) % 9917;

            j++;

        }

        else {

            v[k] = a[i];

            i++;

        }

    }

}



void merge_sort(int *v, int n) {

    if (n > 1) {

        int mid = n / 2, k = 0;

        int a[mid + 1], b[mid + 1];

        for (int i = 0; i < mid; i++)

            a[i] = v[i];

        for (int i = mid; i < n; i++)

            b[k++] = v[i];

        merge_sort(a, mid);

        merge_sort(b, mid + n % 2);

        sortare_interclasare(v, a, b, n);

    }

}



int main() {

    freopen("inv.in", "r", stdin);

    freopen("inv.out", "w", stdout);

    int n, numar;

    scanf("%d", &n);

    int numere[n];

    for (int i = 0; i < n; i++) {

        scanf("%d", &numar);

        numere[i] = numar;

    }

    merge_sort(numere, n);

    printf("%d ", nr_inversiuni);

    return 0;

}
