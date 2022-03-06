#include <fstream>






int v[20][250000];



int main()

{

 std::ifstream fin("stramosi.in");

 std::ofstream fout("stramosi.out");



 int n, m;

 fin >> n >> m;



 for (int i = 1; i <= n; i++)

  fin >> v[0][i];



 for(int i = 1; i<= 17; i++)

  for(int j = 1; j <= n; j++)

   v[i][j] = v[i - 1][v[i - 1][j]];



 while (m--) {

  int p, q;

  fin >> q >> p;



  for(int i = 17; i >= 0; i--)

   if ((1 << i) <= p) {

    q = v[i][q];

    p -= (1 << i);

   }



  fout << q << "\n";

 }



 fin.close(), fout.close();



 return 0;

}
