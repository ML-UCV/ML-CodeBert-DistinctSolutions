#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<cstring>


using namespace std;



ifstream fin ("swap.in");

ofstream fout ("swap.out");



vector <int> h[27];

vector <int> L[27];

int P[50010], n, cnt;

char a[50010], b[50010];



void read()

{

   int i, j, ok;

   fin >> a >> b;

   n = strlen(a);



   for (i=n; i>=1; i--)

   {

      a[i] = a[i-1];

      b[i] = b[i-1];

   }



   for (i=0; i<=26; i++)

   {

      for (j=1; j<=n; j++)

      {

         if (b[j] - 'a' == i)

         h[i].push_back(j);

         if (a[j] - 'a' == i)

         L[i].push_back(j);

      }

   }



   ok = 1;

   for (i=0; i<=26 && ok==1; i++)

    if (h[i].size() != L[i].size())

        ok = 0;



   if (ok == 0)

   {

       fout << "-1\n";

       exit(0);

   }



   for (i=n; i>=1; i--)

   { j = a[i]-'a';

     P[i] = h[j][h[j].size()-1];

     h[j].pop_back();

   }

}



void merge(int st, int m, int dr)

{

    int Q[50009], i, j, k;

    i = st;

    j = m+1;

    k = 0;

    while (i <= m && j <= dr)

    {

        if (P[i] <= P[j])

            Q[++k] = P[i++];

        else

        {

            Q[++k] = P[j++];

            cnt += (m - i + 1);

        }

    }

    while (i <= m)

        Q[++k] = P[i++];

    while (j <= dr)

        Q[++k] = P[j++];



    j = st;

    for (i = 1; i <= k; ++i)

        P[j++] = Q[i];

}



void Interschimba(int i, int j)

{

    if (P[i] > P[j])

    {

        cnt++;

        swap(P[i], P[j]);

    }

}



void MergeSort(int st, int dr)

{

    int m, i;

    if (dr - st <= 1) Interschimba(st, dr);

    else

    {

        m = (st + dr) / 2;

        MergeSort(st, m);

        MergeSort(m + 1, dr);

        merge(st, m, dr);

    }

}



int main ()

{

  read();

  MergeSort(1,n);

  fout << cnt << "\n";

  fin.close();

  fout.close();

  return 0;

}
