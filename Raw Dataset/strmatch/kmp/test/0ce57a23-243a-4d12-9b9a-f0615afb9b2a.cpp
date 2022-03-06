#include <bits/stdc++.h>


using namespace std;



ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");
const int Nmax = 2000005;

const short L = 1000;





char s1[Nmax] , s2[Nmax];





vector < int > ans;



int n , m , pref[Nmax] , dim , k;



int main()

{

    fin >> (s1 + 1);

    n = strlen(s1 + 1);

    fin >> (s2 + 1);

    m = strlen(s2 + 1);

    for(int i = 2 ; i <= n ; i++)

    {

        while(k > 0 && s1[k + 1] != s1[i])

            k = pref[k];

        if(s1[k + 1] == s1[i])

            k++;

        pref[i] = k;

    }

    k = 0;

    for(int i = 1 ; i <= m ; i++)

    {

        while(k > 0 && s1[k + 1] != s2[i])

            k = pref[k];

        if(s1[k + 1] == s2[i])

            ++k;

        if(k == n)

        {

            ++dim;

            if(dim <= L)

                ans.push_back(i - n);

        }

    }

    fout << dim << "\n";

    for(auto &it : ans)

        fout << it << " ";

    fout << "\n";

    fin.close();

    fout.close();

    return 0;

}
