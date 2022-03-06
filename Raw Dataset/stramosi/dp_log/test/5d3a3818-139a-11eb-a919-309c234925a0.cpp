#include <iostream>
#include <fstream>


using namespace std;



int dk[19][250005];



int main()

{

 ifstream cin("stramosi.in");

 ofstream cout("stramosi.out");

 ios_base::sync_with_stdio(false);

 cin.tie(0); cout.tie(0);

 int n, m, q , p,i,j;

 cin >> n >> m;

 for(j = 1; j <= n; j++)

  cin >> dk[0][j];

 for (i = 1; i < 19; i++)

  for (j = 1; j <= n; j++)

   dk[i][j] = dk[i - 1][dk[i - 1][j]];

 while (m--)

 {

  cin >> q >> p;

  for (i = 0; i < 19; i++)

   if (p & (1 << i))

    q = dk[i][q];

  cout << q << "\n";

 }

 return 0;

}
