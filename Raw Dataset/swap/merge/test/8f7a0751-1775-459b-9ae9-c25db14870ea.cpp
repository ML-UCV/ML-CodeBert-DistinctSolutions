#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;



const int nmax = 51200;

int seq[nmax], nseq[nmax];



int go(int lo, int hi) {

 if (lo >= hi) return 0;



 int mid = (lo + hi) >> 1;

 int res = go(lo, mid) + go(mid+1, hi);



 int i = lo, j = mid+1, k = lo;

 while (i <= mid && j <= hi) {

  if (seq[i] <= seq[j]) {

   nseq[k++] = seq[i++];

  } else {

   nseq[k++] = seq[j++];

   res += mid + 1 - i;

  }

 }

 while (i <= mid) {

  nseq[k++] = seq[i++];

 }

 while (j <= hi) {

  nseq[k++] = seq[j++];

 }



 for (i = lo; i <= hi; ++i) seq[i] = nseq[i];

 return res;

}



int main() {

 freopen("swap.in", "rt", stdin);

 freopen("swap.out", "wt", stdout);



 char s1[nmax], s2[nmax];

 fgets(s1, 50001, stdin);

 fgets(s2, 50001, stdin);



 int N = strlen(s1);

 if (strlen(s2) != N) {

  printf("-1\n");

  return 0;

 }



 deque<int> pos[32];

 for (int i = 0; i < N; ++i)

  pos[s1[i]-'a'].push_back(i);



 for (int i = 0; i < N; ++i) {

  int ind = s2[i]-'a';

  if (pos[ind].empty()) {

   printf("-1\n");

   return 0;

  }

  seq[i] = pos[ind].front();

  pos[ind].pop_front();

 }



 printf("%d\n", go(0, N-1));



 return 0;

}
