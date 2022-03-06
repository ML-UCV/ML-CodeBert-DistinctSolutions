#include <cstdio>


using namespace std;

char s1[50000 + 2], s2[50000 + 2];

int aib[50000 + 1], next[50000], ut[26];

int n;

int fr1[26], fr2[26];



inline int ultb(int x){

  return x & (-x);

}



int suma(int x){

  if(x == 0)

    return 0;

  return aib[x] + suma(x - ultb(x));

}



void add(int x, int d){

  if(x <= n){

    aib[x] += d;

    add(x + ultb(x), d);

  }

}



int main(){

  FILE *in = fopen("swap.in", "r");

  fgets(s1, 50000 + 2, in);

  fgets(s2, 50000 + 2, in);

  n = 0;

  while(s1[n] >= 'a' && s1[n] <= 'z'){

    next[n] = ut[s1[n] - 'a'];

    ut[s1[n] - 'a'] = n;

    n++;

  }

  fclose(in);

  int i, p, rez = 0;

  for(i = 0; i < n; i++){

    s1[i] -= 'a';

    s2[i] -= 'a';

    fr1[s1[i]]++;

    fr2[s2[i]]++;

  }

  bool cnt = 1;

  for(i = 0; i < 26; i++)

    if(fr1[i] != fr2[i])

      cnt = 0;

  FILE *out = fopen("swap.out", "w");

  if(cnt == 0)

    fprintf(out, "-1");

  else{

    for(i = 1; i <= n; i++)

      aib[i] = ultb(i);

    for(i = n - 1; i >= 0; i--){

      p = ut[s2[i]];

      ut[s2[i]] = next[ut[s2[i]]];

      rez += suma(n) - suma(p + 1);

      add(p + 1, -1);

    }

    fprintf(out, "%d", rez);

  }

  fclose(out);

  return 0;

}
