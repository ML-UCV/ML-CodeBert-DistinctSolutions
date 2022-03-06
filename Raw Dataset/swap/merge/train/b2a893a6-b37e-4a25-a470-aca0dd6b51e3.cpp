#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;



const int MAX_N = 50010;

const int MAX_L = 28;



int f[2][MAX_L], d[MAX_N], c[MAX_N], sol;

char a[MAX_N], b[MAX_N];

vector<int> v[MAX_L];



void merge(int st, int dr)

{

 int i, j, k;

 int mid = st + (dr - st) / 2;

 if (st >= dr) return;



 merge(st, mid);

 merge(mid + 1, dr);



 i = st;

 j = mid + 1;

 k = st - 1;



 while (i <= mid && j <= dr)

 {

  if (d[i] < d[j]) c[++k] = d[i++];

  else

  {

   sol += (mid - i + 1);

   c[++k] = d[j++];

  }

 }



 if (i <= mid)

   for (; i <= mid; ++i) c[++k] = d[i];

 else for (i = j; i <= dr; ++i) c[++k] = d[i];



 for (i = st; i <= dr; ++i) d[i] = c[i];

}



int main()

{

 freopen("swap.in", "r", stdin);

 freopen("swap.out", "w", stdout);



 scanf("%s\n", a + 1);

 scanf("%s\n", b + 1);

 int l = strlen(a + 1);



 for (int i = 1; i <= l; ++i)

 {

  ++f[1][b[i] - 'a'];

  v[b[i] - 'a'].push_back(i);

 }



 for (int i = 1; i <= l; i++)

 {

  ++f[0][a[i] - 'a'];

  if (f[0][a[i] - 'a'] > f[1][a[i] - 'a'])

  {

   printf("-1\n");

   return 0;

  }

  d[i] = v[a[i] - 'a'][f[0][a[i] - 'a'] - 1];

 }



 merge(1, l);



 printf("%d\n", sol);

}
