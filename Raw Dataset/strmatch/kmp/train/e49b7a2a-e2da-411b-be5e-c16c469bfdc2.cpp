#include <bits/stdc++.h>


using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



int pi[2000005],poz[1024],m,n,cnt;

char a[2000005],b[2000005];



void make_prefix()

{

 int i, q = 0;



 for (i = 2, pi[1] = 0; i <= m; ++i)

 {

  while (q && a[q+1] != a[i])

        {

   q = pi[q];

        }

  if (a[q+1] == a[i])

        {

   ++q;

        }

  pi[i] = q;

 }

}

int main()

{

    char car;

    fin>>noskipws>>car;

    while(car!='\n')

    {

        a[++n]=car;

        fin>>noskipws>>car;

    }

    fin>>noskipws>>car;

    while(car!='\n')

    {

        b[++m]=car;

        fin>>noskipws>>car;

    }



    make_prefix();



    int q=0;



    for (int i = 1; i <= m; ++i)

 {

  while (q && a[q+1] != b[i])

        {

   q = pi[q];

        }

  if (a[q+1] == b[i]) q++;



  if (q == n)

  {

   q = pi[n];

   cnt++;

   if (cnt <= 1000) poz[cnt] = i-n;

  }

 }

 fout<<cnt<<'\n';

    for(int i=1;i<=min(cnt,1000);i++)

        fout<<poz[i]<<" ";

}
