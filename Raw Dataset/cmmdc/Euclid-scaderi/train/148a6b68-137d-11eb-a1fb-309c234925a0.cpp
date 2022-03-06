#include<stdio.h>


int main()

{

 int a,b;

 FILE* p,*q;

 p = fopen("cmmdc.in", "r");

 q = fopen("cmmdc.out", "w");

 fscanf(p,"%d%d", &a,&b);



 while (a != b)

  if (a > b)

   a = a - b;

  else

   b = b - a;

 if (a == 1)

  fprintf(q, "%c", '0');

 else

  fprintf(q, "%d", a);

 fclose(p);

 fclose(q);

 return 0;

}
