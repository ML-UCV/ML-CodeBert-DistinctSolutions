#include <bits/stdc++.h>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

int p[2000005];

char A[2000005],B[2000005];

vector <int> Sol;

int main()

{

    f>>A>>B;

    int n=strlen(A);

    for(int i=1,j=0; A[i];)

    {

        if(A[i]==A[j])

            p[i]=++j,i++;

        else

        {

            if(j)

                j=p[j-1];

            else

                i++;

        }

    }

    for(int i=0,j=0; B[i];)

    {

        if(B[i]==A[j])

            i++,j++;

        if(j==n)

        {

            Sol.push_back(i-j);

            j=p[j-1];

        }

        else if(B[i]!=A[j])

        {

            if(j)

                j=p[j-1];

            else

                i++;

        }

    }

    g<<Sol.size()<<'\n';

    for(int i=0;i<Sol.size()&&i<1000;i++)

        g<<Sol[i]<<' ';

    return 0;

}
