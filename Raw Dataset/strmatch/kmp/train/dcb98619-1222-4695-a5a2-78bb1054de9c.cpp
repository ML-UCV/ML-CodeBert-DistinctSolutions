#include <bits/stdc++.h>


using namespace std;



ifstream in;

ofstream out;



string pat, s;

vector<int> sec,sol;



void pattern()

{

 sec.push_back(0);

 int z = 1;

 while (z<pat.size())

 {

  if (pat[0] == pat[z])

  {

   int nr = 1, d1 = 0;

   while (pat[z]==pat[d1] and z < pat.size())

   {

    sec.push_back(nr);

    nr++;

    z++;

    d1++;

   }

  }

  else

  {

   sec.push_back(0);

   z++;

  }

 }

}



void kmp()

{

 int n,j=0,i=0;

 n = s.size();

 while (j<n)

 {

  if (s[j] == pat[i])

  {

   j++;

   i++;

  }

  if (i == pat.size())

  {

   sol.push_back(j - i);

   i = sec[i - 1];

  }

  else if (j < n and pat[i] != s[j])

  {

   if (i != 0)

    i = sec[i - 1];

   else

    j++;

  }

 }

}



int main()

{

 in.open("strmatch.in");

 out.open("strmatch.out");

 in >> pat >> s;



 pattern();

 kmp();

 int k;

 if (1000 > sol.size())

  k = sol.size();

 else

  k = 1000;

 out << sol.size() << endl;

 for (int i = 0; i < k; i++)

  out << sol[i] << " ";

}
