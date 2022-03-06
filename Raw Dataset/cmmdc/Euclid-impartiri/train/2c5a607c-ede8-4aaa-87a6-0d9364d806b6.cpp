#include "stdio.h"

int cmmdc(int a, int b)
{
 if(b==0)
  if(a==1)
   return 0;
  else
   return a;
 else
  return cmmdc(b, a%b);
}

int main()
{
 int a, b;

 FILE* in = fopen("cmmdc.in", "r");
 FILE* out = fopen("cmmdc.out", "w");

 fscanf(in, "%d %d", &a, &b);
 fprintf(out, "%d", cmmdc(a, b));

 fclose(in);
 fclose(out);
}
