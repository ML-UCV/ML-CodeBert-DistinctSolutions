#include <bits/stdc++.h>


using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



int n, m, l;

int lps[2000005], sol[1005];

string text, pattern;



void build_lps();

void solve();



int main()

{



    fin >> pattern >> text;

    n = text.length();

    m = pattern.length();



    build_lps();

    solve();



    fout << l << "\n";

    l = min(l, 1000);

    for(int i = 1; i <= l; ++i) fout << sol[i] << " ";



    return 0;

}



void build_lps(){



    int len = 0, i = 1;



    while(i < m){

        if(pattern[i] == pattern[len]){

            lps[i++] = ++len;

        }

        else{

            if(len){

                len = lps[len - 1];

            }

            else{

                lps[i++] = 0;

            }

        }

    }



}



void solve(){



    int i = 0, j = 0;



    while(i < n){

        if(text[i] == pattern[j]){

            ++i;

            ++j;

        }



        if(j == m){

            ++l;

            if(l <= 1000) sol[l] = i - j;

            j = lps[j - 1];

        }

        else if(i < n && text[i] != pattern[j]){

            if(j != 0){

                j = lps[j - 1];

            }

            else ++i;

        }

    }



}
