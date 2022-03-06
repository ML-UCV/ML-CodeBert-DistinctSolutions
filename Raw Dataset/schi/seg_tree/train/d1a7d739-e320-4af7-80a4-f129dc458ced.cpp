#include <fstream>
using namespace std;



const int NMAX = 30000;



int c_partial[1 + NMAX];

int c_final[1 + NMAX];



int aint[3 * NMAX];



void build(int idx, int st, int dr)

{

  aint[idx] = dr - st + 1;



  if (st == dr)

  {



    return;

  }



  int mij = (st + dr) / 2;

  int fiu_st = idx * 2;

  int fiu_dr = idx * 2 + 1;



  build(fiu_st, st, mij);

  build(fiu_dr, mij + 1, dr);





}



int query(int idx, int st, int dr, int val)

{

  aint[idx]--;



  if (st == dr)

  {

    return st;

  }



  int mij = (st + dr) / 2;

  int fiu_st = idx * 2;

  int fiu_dr = idx * 2 + 1;



  if (val <= aint[fiu_st])

  {

    return query(fiu_st, st, mij, val);

  }

  else

  {

    return query(fiu_dr, mij + 1, dr, val - aint[fiu_st]);

  }

}



int main()

{

  ifstream in("schi.in");

  ofstream out("schi.out");



  int n;



  in >> n;

  for (int i = 1; i <= n; i++)

  {

    in >> c_partial[i];

  }



  build(1, 1, n);



  for (int i = n; i >= 1; i--)

  {

    int poz = query(1, 1, n, c_partial[i]);

    c_final[poz] = i;

  }



  for (int i = 1; i <= n; i++)

  {

    out << c_final[i] << '\n';

  }



  return 0;

}
