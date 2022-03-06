#include <bits/stdc++.h>


using namespace std;

string A, B;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

int n, m;

int pi[2000005];

vector<int> res;

int nr;



void Read()

{

  f>>A>>B;

  m = A.length();

  n = B.length();



  A.insert(0, " ");

  B.insert(0, " ");

}



void compute()

{

  int q = 0;

  for(int i = 2;i <= m;++i)

  {

    while(q && A[q + 1] != A[i])

      q = pi[q];

    if(A[q + 1] == A[i])

      ++q;

    pi[i] = q;

  }

}



void KMP()

{

  int q = 0;

  for(int i = 1;i <= n;++i)

  {

    while(q && A[q + 1] != B[i])

      q = pi[q];

    if(A[q + 1] == B[i])

      ++q;

    if(q == m)

    {

      ++nr;

      q = pi[q];

      if(nr <= 1000)

        res.push_back(i - m);

    }

  }

}



void Print()

{

  g<<nr<<'\n';

  for(vector<int>::iterator it = res.begin();it != res.end();++it)

    g<<*it<<" ";

}

int main()

{

  Read();

  compute();

  KMP();

  Print();

  return 0;

}
