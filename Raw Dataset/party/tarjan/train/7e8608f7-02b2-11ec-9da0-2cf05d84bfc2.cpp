#include <algorithm>
#include <stdio.h>
#include <time.h>






using namespace std;



int n, m;

int pr[3][1024];

int cond[1024], val[1024];



inline int probeaza(int ind)

{

 if (cond[ind] == 0)

  return (val[pr[0][ind]] | val[pr[1][ind]]);

 if (cond[ind] == 3)

  return ((!val[pr[0][ind]]) | (!val[pr[1][ind]]));

 return (val[pr[0][ind]] | (!val[pr[1][ind]]));

}



int main()

{

 srand(time(0));

 freopen("party.in", "r", stdin);

 freopen("party.out", "w", stdout);



 scanf("%d %d", &n, &m);



 for (int i = 1; i <= m; i++)

 {

  scanf("%d %d %d", &pr[0][i], &pr[1][i], &cond[i]);



  if (cond[i] == 2)

  {

   swap(pr[0][i], pr[1][i]);

   cond[i] = 1;

  }

 }



 for (int i = 1; i <= n; i++)

  val[i] = 0;



 for (int ok = 0; !ok; )

 {

  ok = 1;

  for (int i = 1; i <= m; i++)

   if (!probeaza(i))

   {

    ok = 0;



    int sch = rand() % 2;

    val[pr[sch][i]] ^= 1;

   }

 }



 int nr = 0;

 for (int i = 1; i <= n; i++)

  nr += val[i];



 printf("%d\n", nr);

 for (int i = 1; i <= n; i++)

  if (val[i])

   printf("%d\n", i);



 fclose(stdin);

 fclose(stdout);

 return 0;

}
