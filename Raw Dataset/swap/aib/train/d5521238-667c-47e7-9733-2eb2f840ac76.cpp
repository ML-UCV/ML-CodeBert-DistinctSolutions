#include <fstream>
#include <vector>
#include <algorithm>



using namespace std;

ifstream fin("swap.in");
ofstream fout("swap.out");

int N, i, j, aib[50005];
int ind[135], poz[50005];
long long ANS;
string s1, s2, cop1, cop2;
vector <int> V[135];

int zero(int nr)
{
 return nr & (-nr);
}

void Update(int nr)
{
 while (nr<=N)
 {
  aib[nr]++;
  nr+=zero(nr);
 }
}

int Query(int nr)
{
 int ans=0;
 while (nr>0)
 {
  ans+=aib[nr];
  nr-=zero(nr);
 }
 return ans;
}

int main()
{
 fin >> s1 >> s2;
 cop1=s1;
 cop2=s2;
 sort(cop1.begin(), cop1.end());
 sort(cop2.begin(), cop2.end());
 if (cop1!=cop2)
 {
  fout << -1;
  fin.close();
  fout.close();
  return 0;
 }
 N=s1.size();
 s1='*'+s1;
 s2='*'+s2;
 for (i=1; i<=N; i++)
   V[s2[i]].push_back(i);
 for (i=1; i<=N; i++)
 {
  poz[V[s1[i]][ind[s1[i]]]]=i;
  ind[s1[i]]++;
 }
 for (i=1; i<=N; i++)
 {
  ANS+=poz[i]-Query(poz[i])-1;
  Update(poz[i]);
 }
 fout << ANS << '\n';
 fin.close();
 fout.close();
 return 0;
}
