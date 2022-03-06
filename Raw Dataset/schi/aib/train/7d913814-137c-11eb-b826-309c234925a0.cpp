#include <fstream>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iomanip>
#include <stack>
#include <string.h>
#include <set>


using namespace std;

ifstream f("schi.in");
ofstream g("schi.out");

const int DIM = 3e4 + 17;

int aib[DIM];
int indx[DIM];
int v[DIM];

int n;

void update(int pos, int val)
{
 for(int i = pos; i <= n; i += i & (-i))
 {
  aib[i] += val;
 }
}

int sum(int pos)
{
 int s = 0;

 for(int i = pos; i >= 1; i -= i & (-i))
  s += aib[i];

 return s;
}

int main()
{
 f >> n;

 for(int i = 1; i <= n; i++)
 {
  f >> v[i];
  update(i, 1);
 }


 for(int i = n; i >= 1; i--)
 {
  int pos = 0;
  int l = 1;
  int r = n;

  while(l <= r)
  {
   int mid = (l + r) / 2;

   int p = sum(mid);

   if(p >= v[i])
   {
    pos = mid;
    r = mid - 1;
   }
   else
    l = mid + 1;
  }

  indx[pos] = i;

  update(pos, -1);
 }

 for(int i = 1; i <= n; i++)
  g << indx[i] << '\n';
}
