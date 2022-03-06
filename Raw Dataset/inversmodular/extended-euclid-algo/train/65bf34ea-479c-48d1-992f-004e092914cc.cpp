#include <bits/stdc++.h>


long long a,n;

void cmmdc(long long a,long long b,long long *x,long long *y)

{

  long long x0,y0;

  if (b==0)

    *x=1,*y=0;

  else

  {

    cmmdc(b,a%b,&x0,&y0);

    *x = y0;

    *y = x0 - (a / b) * y0;

  }

}

int32_t main()

{

  long long x,y;

  freopen("inversmodular.in","r",stdin);

  freopen("inversmodular.out","w",stdout);

  scanf("%d %d",&a,&n);

  cmmdc(a,n,&x,&y);

  printf("%d",((x%n)+n)%n);

  return 0;

}
