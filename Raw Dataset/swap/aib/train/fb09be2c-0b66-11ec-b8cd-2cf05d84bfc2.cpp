#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;



const int N = 50000 + 7;

int n;

string s;

string t;

int aib[N];

vector<int> p[26];



void add(int i, int x)

{

    while (i <= n)

    {

        aib[i] += x;

        i += i & (-i);

    }

}



int get(int i)

{

    int ans = 0;

    while (i)

    {

        ans += aib[i];

        i -= i & (-i);

    }

    return ans;

}



int main()

{

    freopen ("swap.in", "r", stdin);

    freopen ("swap.out", "w", stdout);



    cin >> s >> t;

    n = (int) s.size();

    s = "." + s;

    t = "." + t;

    for (int i = 1; i <= n; i++)

    {

        int c = s[i] - 'a';

        p[c].push_back(i);

    }

    for (int i = 1; i <= n; i++)

    {

        add(i, +1);

    }

    for (int c = 0; c < 26; c++)

    {

        reverse(p[c].begin(), p[c].end());

    }

    int cost = 0;

    for (int i = 1; i <= n; i++)

    {

        int c = t[i] - 'a';

        if (p[c].empty())

        {

            cout << "-1\n";

            return 0;

        }

        int j = p[c].back();

        p[c].pop_back();

        cost += get(j) - 1;

        add(j, -1);

    }

    cout << cost << "\n";

}
