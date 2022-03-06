#include <bits/stdc++.h>


using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



int prefix[2000005], l1, l2, nr;

char sir1[2000005], sir2[2000005];



vector<int>rez;



void preproc()

{

    int i=1, j=0;

    prefix[0]=0;

    while(i<l1)

    {

        if (sir1[i]==sir1[j])

        {

            j++;

            prefix[i]=j;

            i++;

        }

        else

        {

            if (j==0)

            {

                prefix[i]=0;

                i++;

            }

            else

                j=prefix[j-1];

        }

    }

}



void solve()

{

    int ind1=0;

    for (int i=0; i<l2; ++i)

    {

        if (sir1[ind1]==sir2[i])

        {

            ind1++;

            if (ind1==l1)

            {

                if (nr<1000)

                    rez.push_back(i-l1+1);

                nr++;

                ind1=prefix[ind1-1];

            }

        }

        else

        {

            if (ind1)

            {

                ind1=prefix[ind1-1];

                i--;

            }

        }

    }

    g <<nr << '\n';

    for (auto &v:rez)

        g << v <<' ';

}



int main()

{

    f >> sir1;

    f >> sir2;

    l1=strlen(sir1);

    l2=strlen(sir2);

    preproc();

    solve();

    return 0;

}
