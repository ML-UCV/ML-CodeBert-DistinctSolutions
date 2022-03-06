#include <bits/stdc++.h>
using namespace std;

ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

int main() {
    string a; fin >> a; int m = a.size();
    string b; fin >> b; int n = b.size();

    int k = 0;
    vector<int> pi(m);
    for (int i = 1; i < m; i++) {
        while (k && a[k] != a[i])
            k = pi[k - 1];
        if (a[k] == a[i])
            k++;
        pi[i] = k;
    }

    int cnt = 0;
    vector<int> sol;

    k = 0;
    for (int i = 0; i < n; i++) {
        while (k && a[k] != b[i])
            k = pi[k - 1];
        if (a[k] == b[i])
            k++;
        if (k == m) {
            cnt++;
            if ((int) sol.size() < 1000)
                sol.push_back(i - m + 1);
            k = pi[k - 1];
        }
    }

    fout << cnt << '\n';
    for (int pos : sol)
        fout << pos << ' ';
    fout << '\n';

    fout.close();
    return 0;
}
