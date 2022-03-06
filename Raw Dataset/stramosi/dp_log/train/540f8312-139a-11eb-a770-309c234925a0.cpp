#include <iostream>
#include <fstream>


using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



const int N = 250005, LOG = 18;



int n, q;

int t[LOG][N];



void precompute()

{

 for (int lvl = 1; (1 << lvl) <= n; lvl++)

 {

  for (int i = 1; i <= n; i++)

  {

   t[lvl][i] = t[lvl - 1][t[lvl - 1][i]];

  }

 }

}



int SolveQuery(int membru, int nr)

{

 int ans = membru;

 for (int bit = 0; bit < 18; bit++)

 {

  if (nr & (1 << bit))

  {

   ans = t[bit][ans];

  }

 }

 return ans;

}



int main()

{

 fin >> n >> q;



 for (int i = 1; i <= n; i++)

 {

  fin >> t[0][i];

 }



 precompute();



 while (q--)

 {

  int persona, nr;

  fin >> persona >> nr;

  fout << SolveQuery(persona, nr) << '\n';

 }

}
