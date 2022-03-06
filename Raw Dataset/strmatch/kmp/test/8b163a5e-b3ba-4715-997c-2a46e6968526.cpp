#include <bits/stdc++.h>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int nmax = 4000005;

string a, b;

int n, m, pi[nmax];



int main(){

    fin >> a >> b;

    n = a.size();

    m = b.size();

    a += '#';

    for (int i = 0; i < m; ++i){

        a += b[i];

    }

    vector <int> ans;

    for (int i = 1; i < m + n + 1; ++i){

        int l = pi[i - 1];

        while (l > 0 && a[l] != a[i]) l = pi[l - 1];

        if (a[l] == a[i]) ++l;

        pi[i] = l;

        if (i >= n + 1){

            if (pi[i] == n){

                ans.push_back(i - n - n);

            }

        }

    }

    fout << ans.size() << "\n";

    int cnt = 0;

    for (auto it : ans){

        fout << it << " ";

        ++cnt;

        if (cnt == 1000){

            break;

        }

    }

    fin.close();

    fout.close();

    return 0;

}
