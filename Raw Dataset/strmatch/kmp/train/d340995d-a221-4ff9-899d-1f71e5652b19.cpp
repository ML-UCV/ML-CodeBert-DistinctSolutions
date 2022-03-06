#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

char p[2000005],t[2000005];

int m,n,LPS[2000005],poz[2000005],k;

void lps()

{

  for (int i = 1, j = 0; i < m; ++i) {

        if (p[i] == p[j])

            LPS[i] = ++j;

        else if (j != 0)

            j = LPS[j - 1], --i;

        else

            LPS[i] = 0;

    }

}

void match()

{

    int i = 0, j = 0;

    while(j < n)

    {

        if(p[i] != t[j])

        {

            if(i == 0)

                ++j;

            else

                i = LPS[i - 1];

        }

        else

        {

            ++i;

            ++j;

            if(i == m)

            {

                 poz[k++] = j - i;

                i = LPS[i - 1];





            }

        }

    }

}



int main()

{

    fin.getline(p,2000005);

    fin.getline(t,2000005);

    m = strlen(p);

    n = strlen(t);

    lps();

    match();

    fout << k << "\n";

    if(k > 1000)

        k = 1000;

    for(int i = 0; i < k; i++)

        fout << poz[i] << " ";

    return 0;

}
