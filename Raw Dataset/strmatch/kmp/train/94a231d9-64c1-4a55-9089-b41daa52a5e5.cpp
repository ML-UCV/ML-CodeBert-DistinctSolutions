#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int NMAX = 2000005;

int phi[2 * NMAX];

vector<int>sol;



void kmp(string &s)

{

 phi[0] = -1;

 for (int i = 1; i < s.size(); i++)

 {

  int k = i - 1;

  while (phi[k] != -1 && s[phi[k] + 1] != s[i])

   k = phi[k];

  if (s[phi[k] + 1] == s[i])

   phi[i] = phi[k] + 1;

  else

   phi[i] = -1;

 }

}



int main()

{

 string a, b;

 fin >> a;

 fin >> b;

 string s = a + "#" + b;

 int na = a.size();

 int ns = s.size();

 kmp(s);

 for (int i = na + 1; i < ns; i++)

 {

  if (phi[i] == na-1)

   sol.push_back(i - 2*na);

 }

 int mi = min((int)sol.size(), 1000);

 fout << sol.size() << "\n";

 for (int i = 0; i < mi; i++)

  fout << sol[i] << " ";

 return 0;

}
