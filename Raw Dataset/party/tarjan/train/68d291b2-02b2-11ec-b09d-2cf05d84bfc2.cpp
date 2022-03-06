#include<stdio.h>
#include<vector>
#include<cstdlib>


using namespace std;



bool state[104];

class ecuations

{

public:

 int x, y, z;

 bool ok;



 void updateOk()

 {

  switch (z)

  {

  case 0:

   ok = state[x] || state[y];

   break;

  case 1:

   ok = state[x] || !state[y];

   break;

  case 2:

   ok = !state[x] || state[y];

   break;

  default:

   ok = !state[x] || !state[y];

  }

 }

 ecuations(int X, int Y, int Z)

 {

  x = X;

  y = Y;

  z = Z;

 }



};

vector<ecuations> v;

bool satisfied(int m)

{

 for (int i = 0; i < m; ++i)

 {

  v[i].updateOk();

  if (!v[i].ok)

  {

   bool aux = rand() % 2;

   if (aux)

    state[v[i].x] = !state[v[i].x];

   else

    state[v[i].y] = !state[v[i].y];



   return false;

  }



 }

 return true;

}



int main()

{



 FILE*f = fopen("party.in", "r");

 int n, m;

 fscanf(f, "%d %d", &n, &m);

 for (int i = 1; i <= m; ++i)

 {

  int x, y, z;

  fscanf(f, "%d%d%d", &x, &y, &z);

  ecuations ec(x, y, z);

  v.push_back(ec);

 }

 fclose(f);





 for (int i = 1; i <= n; ++i)

  state[i] = rand() % 2;







 while (!satisfied(m));



 int nr = 0;

 for (int i = 1; i <= n; ++i)

  nr += state[i];



 FILE*g = fopen("party.out", "w");

 fprintf(g, "%d\n", nr);

 for (int i = 1; i <= n; ++i)

 {

  if (state[i])

   fprintf(g, "%d\n", i);

 }



 return 0;

}
