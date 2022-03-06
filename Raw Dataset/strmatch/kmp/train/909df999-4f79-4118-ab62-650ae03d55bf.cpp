#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

using VI = vector<int>;

const int MaxN = 2000010;
int n, m;
VI pi, res;
char prop[MaxN], word[MaxN];

void Read();
void KMP();
void Write();

int main()
{
 Read();
 KMP();
 Write();
}

void KMP()
{
 pi = VI(n);
 int q{0};
 for (int i = 1; i < n; i++)
 {
  while (q > 0 && word[q] != word[i])
   q = pi[q - 1];
  if (word[q] == word[i])
   q++;
  pi[i] = q;
 }

 q = 0;
 for (int i = 0; i < m; i++)
 {
  while (q > 0 && word[q] != prop[i])
   q = pi[q - 1];
  if (word[q] == prop[i])
   q++;
  if (q == n)
   res.emplace_back(i - n + 1);
 }
}

void Write()
{
 ofstream fout("strmatch.out");
 fout << res.size() << '\n';
 for (int i = 0; i < min(1000, (int)res.size()); i++)
  fout << res[i] << ' ';
}

void Read()
{
 ifstream fin("strmatch.in");
 fin.getline(word, MaxN + 1);
 fin.getline(prop, MaxN + 1);
 n = strlen(word);
 m = strlen(prop);
}
