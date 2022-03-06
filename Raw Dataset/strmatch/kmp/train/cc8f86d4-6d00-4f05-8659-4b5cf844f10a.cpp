#include <bits/stdc++.h>


using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



string A,B;

int n, m;

int pi[20000005];

int nr;

vector<int> res;



void Read()

{

 f>>A;

 f>>B;



 m = A.length();

 n = B.length();



 A.insert(0, " ");

 B.insert(0, " ");



 f.close();

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

   if(res.size() < 1000)

    res.push_back(i - m);

            q = pi[q];

  }

 }

}



void Print()

{

 g<<nr<<'\n';

 for(vector<int>::iterator it = res.begin();it != res.end();++it)

  g<<*it<<" ";

 g.close();

}



int main()

{

 Read();

 compute();

 KMP();

 Print();

 return 0;

}
