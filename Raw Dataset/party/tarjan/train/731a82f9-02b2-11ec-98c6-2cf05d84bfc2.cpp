#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;





int v[2000], x[2000], y[2000], c[2000];



int valid(int i)

{

 switch(c[i])

 {

  case 0: return v[x[i]] || v[y[i]]; break;

  case 1: return v[x[i]] || !v[y[i]]; break;

  case 2: return v[y[i]] || !v[x[i]]; break;

  case 3: return v[x[i]]+v[y[i]] != 2;

 }

 return 1;

}



void random(int i)

{

 int r = rand()%2; r++;

 if(r == 1)

  v[x[i]] = !v[x[i]];

 if(r == 2)

  v[y[i]] = !v[y[i]];

}



int main()

{

 ifstream in("party.in");

 ofstream out("party.out");



 int i, n, m, nr=0;





 in>>n>>m;

 for(i=1; i<=m; i++)

  in>>x[i]>>y[i]>>c[i];





 for(i=1; i<=n; i++)

  v[i] = 1;

 while(1)

 {

  for(i=1; i<=m; i++)

   if(valid(i) == 0)

   {

    random(i);

    break;

   }

  if(i == m+1)

   break;

 }





 for(i=1; i<=n; i++)

  if(v[i])

   nr++;

 out<<nr<<'\n';

 for(i=1; i<=n; i++)

  if(v[i])

   out<<i<<'\n';

}
