#include <fstream>
#include <vector>
#include <string>
#include <deque>
using namespace std;



ifstream fin("swap.in");

ofstream fout("swap.out");



const int Lmax = 5 + 50000;



deque<int> poz[30];



string a, b;



int aib[Lmax];

int n;



bool verif = true;



void Solve();

void Update(int p, int x);

int Query(int p);



int main()

{

 fin >> a >> b;



 a = ' ' + a;

 b = ' ' + b;



 n = a.size() - 1;





 Solve();



 if (verif == false)

 {

  fout << -1;

 }

 else

 {

  int ans = 0;



  for (int i = 1; i <= n; ++i)

  {

   int p = poz[b[i] - 'a'].front();

   poz[b[i] - 'a'].pop_front();



   ans += p - 1 - Query(p);

   Update(p, 1);

  }



  fout << ans;

 }

}



void Solve()

{

 int f[30] = {0};



 for (int i = 1; i <= n; ++i)

 {

  poz[a[i] - 'a'].push_back(i);

  ++f[b[i]- 'a'];

 }



 for (int i = 0; i < 26; ++i)

  if (poz[i].size() != f[i])

   verif = false;

}



void Update(int p, int x)

{

 for (int i = p; i <= n; i += i & -i)

  aib[i] += x;

}



int Query(int p)

{

 int sum = 0;

 for (int i = p; i >= 1; i -= i & -i)

  sum += aib[i];

 return sum;

}
