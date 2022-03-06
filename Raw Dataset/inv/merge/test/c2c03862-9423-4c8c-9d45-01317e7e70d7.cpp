#include <bits/stdc++.h>
using namespace std;



ifstream in("inv.in");

ofstream out("inv.out");



int n, a[100100], aux[100100], vf;



int rec(int st, int dr) {

    if (st == dr)

        return 0;



    int mid = (st + dr) / 2;

    int cnt = rec(st, mid) + rec(mid + 1, dr);

    cnt %= 9917;



    int p1 = st;

    int p2 = mid + 1;



    vf = 0;

    for (int i = st; i <= dr; i++) {

        if (p1 > mid) {

            aux[++vf] = a[p2++];

            if (a[p1] > a[dr]) {

                cnt += dr - mid;

                cnt %= 9917;

            }

            continue;

        }

        if (p2 > dr) {

            aux[++vf] = a[p1++];

            continue;

        }

        if (a[p1] <= a[p2])

            aux[++vf] = a[p1++];

        else {

            aux[++vf] = a[p2++];

            cnt += mid - p1 + 1;

            cnt %= 9917;

        }

    }

    for (int i = st; i <= dr; i++)

        a[i] = aux[i - st + 1];



    return cnt;

}



int main() {

    in >> n;

    for (int i = 1; i <= n; i++)

        in >> a[i];



    out << rec(1, n);



    return 0;

}
