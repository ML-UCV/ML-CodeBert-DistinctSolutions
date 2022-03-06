#include <stdio.h>




void euclidExtins(long long a, long long b, long long& d, long long& x, long long& y)

{

 if (!b)

 {

  x = 1;

  y = 0;

  d = a;

 }

 else

 {

  euclidExtins(b, a % b, d, x, y);

  long long x0 = x;

  long long y0 = y;

  x = y0;

  y = x0 - (a / b) * y0;

 }

}

int main()

{

 FILE* fin = fopen("inversmodular.in", "r");

 FILE* fout = fopen("inversmodular.out", "w");



 long long a, b, d=0;

 fscanf(fin, "%lld%lld", &a, &b);

 long long x = 0, y = 0;

 euclidExtins(a, b, d, x, y);

 if(x>=0)

 fprintf(fout, "%lld",x);

 else

  fprintf(fout, "%lld", b+x%b);

}
