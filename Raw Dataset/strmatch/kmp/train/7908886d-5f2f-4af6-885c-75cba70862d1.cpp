#include <bits/stdc++.h>


using namespace std;



ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");



const int DIM = 2000000 + 5;



char s[DIM], t[DIM];



int pref[DIM], sol[DIM];



void prefix(int n)

{

    pref[1] = 0;

    int k = 0;

    for(int i = 2; i <= n; ++i) {

        while(k > 0 && s[i] != s[k + 1]) k = pref[k];

        if(s[i] == s[k + 1]) ++k;

        pref[i] = k;

    }

}



int main()

{

    fin >> (s + 1) >> (t + 1);

    int szs = strlen(s + 1), szt = strlen(t + 1);

    prefix(szs);

    int cnt = 0;

    for(int i = 1; i <= szt; ++i) {

        while(cnt > 0 && t[i] != s[cnt + 1]) cnt = pref[cnt];

        if(t[i] == s[cnt + 1]) ++cnt;

        if(cnt >= szs) {

            if(sol[0] < 1000) sol[++sol[0]] = i - szs;

            else ++sol[0];

        }

    }

    fout << sol[0] << "\n";

    for(int i = 1; i <= min(sol[0], 1000); ++i) fout << sol[i] << " ";

    return 0;

}
