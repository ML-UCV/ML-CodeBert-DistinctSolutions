#include <bits/stdc++.h>
using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



char a[2000005];

char b[2000005];

int table[2000005];

vector < int > v;

int ans;



int main()

{

    f >> a >> b;

    int m = strlen(a);

    int n = strlen(b);

    int len = 0;

    table[0] = 0;

    for (int i=1;i<m;i++) {

        if (a[i]==a[len]) {

            len++;

            table[i] = len;

        }

        else if (len!=0) {

            len = table[len-1];

            i--;

        }

    }

    int i=0,j=0;

    while (i<n) {

        if (b[i]==a[j]) {

            i++;

            j++;

        }

        if (j==m) {

            ans++;

            if (ans<=1000) {

                v.push_back(i-j);

            }

            j = table[j-1];

        }

        else if (i < n && b[i]!=a[j]) {

            if (j!=0) {

                j = table[j-1];

            }

            else {

                i++;

            }

        }

    }

    g << ans <<'\n';

    for (int o=0;o<v.size();o++) {

        g << v[o] << " ";

    }

    return 0;

}
