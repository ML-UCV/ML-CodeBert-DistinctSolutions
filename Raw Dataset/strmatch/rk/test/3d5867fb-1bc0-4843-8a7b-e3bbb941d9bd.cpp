#include <bits/stdc++.h>






using namespace std;

ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");

int n, m;

int p[2000005], h[2000005], h2[2000005], p2[2000005];

long long hs, hs2;

char s[2000005], t[2000005];

vector<int> rez;

int main()

{

    fin.getline(s, 2000005);

    fin.getline(t, 2000005);

    n = strlen(t);

    m = strlen(s);

    p[0] = p2[0] = 1;

    for(int i=1; i<=n; i++)

        p[i] = (1LL*p[i-1]*31)%int(1e9+9), p2[i] = (1LL*p2[i-1]*53)%int(1e9+9);

    for(int i=0; i<n; i++)

        h[i] = 1LL*(((i>0)? h[i-1]: 0) + 1LL*p[i]*(t[i]-'0'+1) %int(1e9+9))%int(1e9+9);

    for(int i=0; i<m; i++)

        hs = (1LL*(hs + 1LL*p[i]*(s[i]-'0'+1)%int(1e9+9)))%int(1e9+9);

    int nr = 0;

    for(int i=m-1; i<n; i++)

        if( ((1LL*hs*p[i-m+1])%int(1e9+9)) == (1LL*(h[i]- ((i>=m)?h[i-m]:0)+int(1e9+9))%int(1e9+9)))

        {

            if(nr<1000)

                rez.push_back(i-m+1);

            nr++;

        }

    fout << nr << '\n';

    nr = 0;

    for(auto it:rez)

        if(nr > 1000)

            break;

        else fout << it << ' ', nr++;

    return 0;

}
