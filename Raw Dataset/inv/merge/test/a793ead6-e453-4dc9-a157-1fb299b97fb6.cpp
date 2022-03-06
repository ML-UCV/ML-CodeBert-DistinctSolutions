#include <bits/stdc++.h>
using namespace std;





int a[100001], n, b[100001];



long long merge(int a[], int b[], int low, int mid, int high);



long long mergesort(int a[], int b[], int low, int high) {

    long long mid, cnt = 0;

    if (low < high) {

        mid = (low + high)/2;

        cnt = (cnt + mergesort(a, b, low, mid) + mergesort(a, b, mid + 1, high) + merge(a, b, low, mid, high)) % 9917;

    }

    return cnt;

}

long long merge(int a[], int b[], int low, int mid, int high) {

    int h, i, j, k;

    long long cnt = 0;

    h = low;

    i = low;

    j = mid + 1;



    while ((h <= mid) && (j <= high)) {

        if (a[h] <= a[j]) {

            b[i] = a[h];

            h++;

        }

        else {

            b[i] = a[j];

            j++;

            cnt = (cnt + mid - h + 1) % 9917;

        }

        i++;

    }

    if (h > mid) {

        for (k = j; k <= high; k++) {

            b[i] = a[k];

            i++;

        }

    }

    else {

        for (k = h; k <= mid; k++) {

            b[i] = a[k];

            i++;

        }

    }

    for (k = low; k <= high; k++) {

        a[k] = b[k];

    }

    return cnt;

}



int main() {

    freopen("inv.in", "r", stdin);

    freopen("inv.out", "w", stdout);



    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        scanf("%d", &a[i]);

    }



    printf("%lld", mergesort(a, b, 0, n - 1));

    return 0;

}
