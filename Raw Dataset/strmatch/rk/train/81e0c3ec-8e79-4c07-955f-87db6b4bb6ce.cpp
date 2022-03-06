#include <bits/stdc++.h>







using namespace std;



ifstream f("strmatch" ".in");

ofstream g("strmatch" ".out");



typedef long long ll;

typedef long double ld;

typedef pair<ll,ll> pii;

typedef pair<ld,ld> pct;



const ll mod = 1e9 + 7;

const ld eps = 1e-9;





void add(ll &a , ll b)

{

    a += b;

    a %= mod;

}



void sub(ll &a, ll b)

{

    a = (a - b + mod) % mod;

}



string txt,pat;

int pi[1000010], d[1000010],ans,cat;

vector<int> sol;

void compute_pattern(string a,int pi[])

{

    int k = 0;

    int n = a.size() - 1;

    pi[1] = 0;

    for(int i = 2; i <= n; ++i)

    {

        while( k > 0 && a[i] != a[k + 1] ) k = pi[k];

        if(a[i] == a[k + 1]) k++;

        pi[i] = k;

    }

}



void find_pattern(string y, string pat,int pi[], int d[])

{

    compute_pattern(pat, pi);

    int m = y.size() - 1;

    int n = pat.size() - 1;

    int k = 0;

    for(int i = 1; i <= m ; ++i)

    {

        while( (k > 0) && (y[i] != pat[k + 1]) ) k = pi[k];

        if(y[i] == pat[k+1]) k++;

        if(k == pat.size() - 1)

        {

            cat++;

            if(cat <= 1000)

                sol.push_back(i - n);

        }

    }

}

int main()

{

    f >> pat >> txt ;

    txt = ' ' + txt;

    pat = ' ' + pat;

    find_pattern(txt, pat, pi, d);

    g << cat << '\n';

    for(auto it : sol)

    {

        g << it << ' ';

        cat--;

        if(cat == 0)

            break;

    }

    f.close();

    g.close();

    return 0;

}
