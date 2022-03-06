#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>


using namespace std;



const int LMAX = 2000000;



char p[LMAX + 5], s[LMAX + 5];

int urm[LMAX + 5];



void prefix(char *pattern, int *urmp) {

  int l = strlen(pattern);



  urmp[1] = 0;

  for(int i = 2; i <= l; i++) {

    int k = urmp[i - 1];



    while(k > 0 && pattern[i - 1] != pattern[k])

      k = urmp[k];



    if(pattern[i - 1] == pattern[k])

      k++;

    urmp[i] = k;

  }

}



void findp(char *pattern, int *urmp, char *str) {

  int crt_match = 0;

  int lp = strlen(pattern), ls = strlen(str);

  vector<int> sol;



  for(int i = 1; i <= ls; i++) {

    while(crt_match > 0 && str[i - 1] != pattern[crt_match])

      crt_match = urm[crt_match];



    if(str[i - 1] == pattern[crt_match])

      crt_match++;

    if(crt_match == lp) {

      sol.push_back(i - lp);

      crt_match = urm[crt_match];

    }

  }



  printf("%d\n", sol.size());

  int cnt = 0;

  for(int match: sol) {

    printf("%d ", match);

    cnt++;

    if(cnt == 1000)

      break;

  }

}



int main() {

  freopen("strmatch.in", "r", stdin);

  freopen("strmatch.out", "w", stdout);



  scanf("%s%s", p, s);



  prefix(p, urm);

  findp(p, urm, s);



  return 0;

}
