#include <bits/stdc++.h>

using namespace std;
int Pi[4000005];
char s[4000005];
ofstream fout ("strmatch.out");
void KMP (int n, int l)
{
    int count = 0;
    Pi[1] = 0;
    for (int i = 2; i<=n; ++i)
    {
        int k = i - 1;
        while (k && s[i] != s[Pi[k] + 1]) {
            k = Pi[k];
        }
        if (s[i] == s[Pi[k] + 1]) {
            Pi[i] = Pi[k] + 1;
        } else {
            Pi[i] = 0;
        }
        if (Pi[i] == l) {
            count += 1;
        }
    }
    fout << count << '\n';
    count = 0;
    for (int i = 2; i <= n; ++i) {
        if (Pi[i] == l)
        {
            ++count;
            if (count<=1000)
                fout << i-l-l-1 << ' ';
        }
    }
}
int main()
{
    ifstream fin ("strmatch.in");
    fin >> (s+1);
    int n = strlen(s+1), l;
    l = n;
    s[n+1] = '%';
    fin >> (s+n+2);
    n = strlen(s+1);
    KMP(n, l);
    return 0;
}
