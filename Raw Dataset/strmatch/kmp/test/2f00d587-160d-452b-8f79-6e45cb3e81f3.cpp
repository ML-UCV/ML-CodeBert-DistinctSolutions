#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;



const int NMAX = 2000005;

string a, b;

string s;

int phi[2*NMAX];



void kmp(string s, int phi[NMAX])

{

 int ns = s.size();

 phi[0] = -1;

 for (int i = 1; i < ns; i++)

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



vector<int>sol;



int main()

{

 ifstream cin("strmatch.in");

 ofstream cout("strmatch.out");

 cin >> a >> b;

 s = (a + '#' + b);

 kmp(s, phi);

 int na = a.size(), nb = b.size(),ns = s.size();

 for (int i = na + 1; i < ns; i++)

  if (phi[i] == na - 1)

   sol.push_back(i - 2 * na);

 cout << sol.size() << "\n";

 int mi = min((int)sol.size(), 1000);

 for (int i = 0; i < mi; i++)

  cout << sol[i] << " ";

 cout << "\n";

 return 0;

}
