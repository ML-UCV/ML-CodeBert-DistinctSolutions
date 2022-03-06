#include <fstream>


using namespace std;



ifstream cin("stramosi.in");

ofstream cout("stramosi.out");
int v[100][150];

int d[18][2500005];



int main()

{



    int n, t;

 cin >> n >> t;



 for (int i = 1; i <= n; i++)

  cin >> d[0][i];



 for (int i = 1; i < 18; i++)

  for (int j = 1; j <= n; j++)

   d[i][j] = d[i - 1][d[i - 1][j]];



 int ans = 0;

 int x, y, k = 0;

 while(t--)

    {

        k = 0;

  cin >> x >> y;



  ans = x;



  while(y)

        {

   if (y % 2 != 0)

                ans = d[k][ans];

   y /= 2;

   k++;

  }



  cout << ans << "\n";

 }



 return 0;

}
