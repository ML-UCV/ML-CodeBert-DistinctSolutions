#include <bits/stdc++.h>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int NMAX = 1e6 + 1;



char txt[2 * NMAX + 1], pat[2 * NMAX + 1];

int lps[2 * NMAX + 1];



void buildlps( int m ) {

  lps[0] = 0;

  int i, len;

  len = 0;

  i = 1;

  while( i < m ) {

    if( pat[len] == pat[i] ) {

      len ++;

      lps[i] = len;

      i ++;

    }

    else {

      if( len == 0 ) {

        lps[i] = 0;

        i ++;

      }

      else

        len = lps[len - 1];

    }

  }

}



int main() {

    int n, m;

    fin>>pat;

    fin>>txt;

    m = strlen(pat);

    n = strlen(txt);

    buildlps(m);

    int i = 0, j = 0;

    vector<int> ans;

    while( i < n ) {

      if( txt[i] == pat[j] ) {

        i ++;

        j ++;

      }

      if( j == m ) {

        ans.push_back(i);

        j = lps[j - 1];

      }

      else if( i < n && txt[i] != pat[j] ) {

        if( j == 0 )

          i ++;

        else

          j = lps[j - 1];

      }

    }

    fout<<ans.size()<<endl;

    for( i = 0; i < min(1000,(int)ans.size()); i ++ )

      fout<<ans[i] - m<<" ";

    return 0;

}
