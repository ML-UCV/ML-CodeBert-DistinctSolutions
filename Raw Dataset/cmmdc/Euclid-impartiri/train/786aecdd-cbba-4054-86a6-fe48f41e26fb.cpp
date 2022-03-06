#include <bits/stdc++.h>
using namespace std;
int cmmdc(int a, int b)
{
 if(b == 0)
  return a;
 else
  return cmmdc(b, a%b);
}
int main()
{
 freopen("cmmdc.in", "r", stdin);
 freopen("cmmdc.out", "w", stdout);
 int a, b;
 scanf("%d%d", &a, &b);
 int c = cmmdc(a, b);
 if(c == 1)
  c = 0;
 printf("%d", c);
 return 0;
}
