#include <bits/stdc++.h>



using namespace std;

int rs = 0;
const int MAXN = 100010;
const int_fast64_t MODULO = 9917;
int n;
int arr[MAXN];

int_fast64_t merge(int left, int mid, int right, int arr[]) {
    queue<int> q1,q2;
    for (int i = left; i <= mid; i++) q1.push(arr[i]);
    for (int i = mid + 1; i <= right; i++) q2.push(arr[i]);

    int index = left;
    int_fast64_t inv = 0;
    int i = left;
    while (!q1.empty() && !q2.empty()) {
        if (q1.front() <= q2.front()) {
            arr[index] = q1.front();
            q1.pop();

        } else {
            arr[index] = q2.front();
            q2.pop();
            inv += q1.size();
        }
        index++;
    }

    while (!q1.empty()) {
        arr[index] = q1.front();
        q1.pop();
        index++;
    }

    while (!q2.empty()) {
        arr[index] = q2.front();
        q2.pop();
        index++;
    }
    return inv;
}

int_fast64_t mergesort(int left, int right, int arr[]) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;

    int_fast64_t inv = mergesort(left, mid, arr);
    inv += mergesort(mid + 1, right, arr);

    inv += merge(left, mid, right, arr);

    return inv;
}

int main() {

    ifstream fin("inv.in");
    ofstream fout("inv.out");

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    fin >> n;
    for (int i = 0; i < n; i++) fin >> arr[i];

    fout << mergesort(0, n - 1, arr) % MODULO;


    return 0;
}
