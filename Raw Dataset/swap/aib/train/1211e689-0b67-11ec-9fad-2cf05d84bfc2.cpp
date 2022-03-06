#include<cstdio>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<unordered_map>
using namespace std;



const int nmax = 50005;

const int alpha = 30;



int n, i, sol, a[nmax], aib[nmax];

int p[alpha], f1[alpha], f2[alpha];

string s, t;



vector<int> v[alpha];



void update(int x)

{

    for(int i = x; i <= n; i += i & (-i))

        aib[i]++;

}



int query(int x)

{

    int r = 0;

    for(int i = x; i; i -= i & (-i))

        r += aib[i];

    return r;

}



int main()

{

    ifstream fin("swap.in");

    ofstream fout("swap.out");



    fin >> s;

    fin >> t;



    n = s.size();



    for(i = 0; i < n; i++)

    {

        f1[s[i] - 'a']++;

        f2[t[i] - 'a']++;

    }



    for(i = 0; i < 26; i++)

        if(f1[i] != f2[i])

        {

            fout << "-1\n";

            return 0;

        }



    for(i = 0; i < n; i++)

        v[s[i] - 'a'].push_back(i + 1);



    for(i = 0; i < n; i++)

        a[i] = v[t[i] - 'a'][p[t[i] - 'a']++];



    for(i = n - 1; i >= 0; i--)

    {

        sol += query(a[i] - 1);

        update(a[i]);

    }



    fout << sol;



    return 0;

}
