#include <bits/stdc++.h>




using namespace std;

ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");

char a[2000005], c;

int rez, m, kmp[2000005];

void build(char a[], int kmp[])

{

    int i = 0, j = 1;

    kmp[0] = 0;

    while(j < m)

    {

        if(a[i] == a[j])

        {

            kmp[j] = i+1;

            i++, j++;

        }

        else if(i)

            i = kmp[i-1];

        else j++;

    }

}

vector<int> sol;

int main()

{

    fin >> a;

    m = strlen(a);

    build(a, kmp);

    int i = 0;

    for(int j=0; fin >> c; j++)

    {

        if(c == a[i])

        {

            if(i == m-1)

            {

                if(rez <= 1000)

                    sol.push_back(j-m+1);

                rez++;

                i = kmp[i];

            }

            else

                i++;

        }

        else

        {

            while(i!=0 && c!=a[i])

                i = kmp[i-1];

            if(c == a[i])

                i++;

        }

    }

    fout << rez << '\n';

    for(int i=0; i<min(rez, 1000); i++)

        fout << sol[i] << ' ';

    return 0;

}
