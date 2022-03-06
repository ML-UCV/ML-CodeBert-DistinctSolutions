#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;



ifstream fin ("inv.in");

ofstream fout ("inv.out");



const int mod = 9917;

int aib[5 + 100000];

int n;

vector<pair<int, int>> v;





void Update(int p, int val)

{

 for (int i = p; i <= n; i += i & -i)

  aib[i] = (aib[i] + val) % mod;

}



int Query(int p)

{

 int suma = 0;

 for (int i = p; i >= 1; i -= i & -i)

  suma = (suma + aib[i]) % mod;



 return suma;

}



int main()

{

 fin >> n;

 v = vector<pair<int, int>>(n);

 int val;

 for (int i = 0; i < n; ++i)

 {

  fin >> val;

  v[i] = {val, i + 1};

 }



 sort(v.begin(), v.end(), greater<pair<int, int>>());



 int res = 0;

 for (auto& p : v)

 {

  res += Query(p.second);

  if (res >= mod)

   res -= mod;

  Update(p.second, 1);

 }



 fout << res;



 return 0;

}
