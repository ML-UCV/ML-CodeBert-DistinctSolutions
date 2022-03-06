#include <cstdio>#include <cstring>
#include <cassert>
#include <string>
using namespace std;
int s[28][50001], L1, L2, ind[28];

int go[50001], c[50001], place[50001];

char sir1[50001], sir2[50001];



void read ()

{

  freopen ("swap.in", "rt", stdin);

  freopen ("swap.out", "wt", stdout);



  fgets(sir1, 50001, stdin);

  fgets(sir2, 50001, stdin);



  L1 = strlen (sir1);

  L2 = strlen (sir2);

}



int LSB (int x)

{

  return x ^ (x-1) & x;

}



void update (int x)

{

  for (; x <= L1 ; x += LSB(x))

    c[x] += 1;

}



int query (int x)

{

  int rez = 0;



  for (; x > 0; x -= LSB(x))

    rez += c[x];

  return rez;

}



void solve ()

{

  int sol = 0;



  if (L1 != L2)

   {

     printf ("-1\n");

     return;

   }



  for (int i = 0; i < L2; ++ i)

    s[sir2[i] - 'a'][ind[sir2[i] - 'a']++] = i + 1;



  memset (ind, 0, sizeof(ind));

  for (int i = 0; i < L1; ++ i)

   {

     go[i + 1] = s[sir1[i] - 'a'][ind[sir1[i] - 'a']++];

     if (!go[i + 1])

      {

        printf ("-1\n");

        return;

      }

     place[go[i + 1]] = i + 1;

   }
  int ii;



  for (int i = 0; i < L1; ++ i)

   {

     ii = place[i+1];

     sol += ii - go[ii] + query (L1) - query (ii);

     update (ii);

   }



  printf ("%d\n", sol);

}



int

 main ()

{

  read ();

  solve ();

  return 0;

}
