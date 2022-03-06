#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



using PII = pair<int, int>;

using VP = vector<PII>;

const int mod = 9917;

int aib[110011], s, n, x;



inline void Update(int poz)

{

 for (int i = poz; i <= n; i += i & -i)

  ++aib[i];

}



inline int Query(int poz)

{

 int sum = 0;

 for (int i = poz; i > 0; i -= i & -i)

  sum += aib[i];

 return sum;

}



int main()

{

 fin >> n;

 VP v(n + 1);

 for (int i = 1; i <= n; ++i)

 {

  fin >> x;

  v[i] = {x, i};

 }

 sort(v.begin() + 1, v.end(), greater<PII>());

 for (int i = 1; i <= n; ++i)

 {

  s = (s + Query(v[i].second)) % mod;

  Update(v[i].second);

 }

 fout << s;

 fin.close();

 fout.close();

 return 0;

}
