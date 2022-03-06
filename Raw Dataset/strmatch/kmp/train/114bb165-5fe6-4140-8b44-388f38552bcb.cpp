#include <cstdio>
#include <cstring>


using namespace std;



char a[2000005], b[2000005];

int pi[2000005];



int main() {

 freopen("strmatch.in", "r", stdin);

 freopen("strmatch.out", "w", stdout);



 int n, m;

 int matches[1005];



 fgets(a+1, sizeof(a), stdin);

 fgets(b+1, sizeof(b), stdin);



 n = strlen(a+1);

    if (a[n] == '\n') {

        a[n] = 0;

        --n;

    }



 m = strlen(b+1);

    if (b[m] == '\n') {

        b[m] = 0;

        --m;

    }



 pi[1] = pi[0] = 0;

 int k=0;



 for(int i=2; i<=n; ++i) {

  while(k > 0 && a[k+1] != a[i])

   k = pi[k];

  if (a[k+1] == a[i])

   ++k;

  pi[i] = k;

 }



 int q=0, matchno = 0;

 for(int i=1; i<=m; ++i) {

  while (q>0 && a[q+1] != b[i])

   q = pi[q];

  if (a[q+1] == b[i])

   ++q;

  if (q == n) {

   if (matchno < 1000)

    matches[matchno] = i - n;

   ++matchno;

   q = pi[n];

  }

 }



 printf("%d\n", matchno);

 for(int i=0; i<matchno && i < 1000; ++i)

  printf("%d ", matches[i]);



 return 0;

}
