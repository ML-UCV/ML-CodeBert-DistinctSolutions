#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;



char a [50005], b [50005];

int x, n, s, fa [30], fb [30], arb [50005<<2];

queue <int> l [30];



void frecv (char x [], int f [])

{

 int i;

 for (i=0; x [i]; ++i)

  ++f [x [i]-'a'];

}



bool egale ()

{

 frecv (a, fa);

 frecv (b, fb);

 int i;

 for (i=0; i < 30; ++i)

  if (fa [i] != fb [i])

   return false;

 return true;

}



void init ()

{

 int i;

 for (i=0; a [i]; ++i)

  l [a [i]-'a'].push (i);

}



void update (int nod, int st, int dr)

{

 if (st == dr)

 {

  ++arb [nod];

  return ;

 }

 int m=(st+dr)/2;

 if (m >= x)

  update (nod<<1, st, m);

 else

  update ((nod<<1)+1, m+1, dr);

 arb [nod]=arb [nod<<1]+arb [(nod<<1)+1];

}



void query (int nod, int st, int dr)

{

 if (dr <= x)

 {

  s+=arb [nod];

  return ;

 }

 int m=(st+dr)/2;

 if (m < x)

  query ((nod<<1)+1, m+1, dr);

 query (nod<<1, st, m);

}



int res ()

{

 n=strlen (a)-1;

 init ();

 int i, r=0;

 for (i=0; b [i]; ++i)

 {

  x=l [b [i]-'a'].front ();

  s=0;

  query (1, 0, n);

  r+=x-s;





  l [b [i]-'a'].pop ();

  update (1, 0, n);

 }

 return r;

}



int main ()

{

 freopen ("swap.in", "r", stdin);

 freopen ("swap.out", "w", stdout);

 fgets (a, 50001, stdin);

 fgets (b, 50001, stdin);

 if (!egale ())

 {

  printf ("-1\n");

  return 0;

 }

 printf ("%d\n", res ());

 return 0;

}
