#include<bits/stdc++.h>
using namespace std;

ifstream fin ("strmatch.in");

ofstream fout("strmatch.out");

int n,prefix[2000006];

char s[2000006],patern[2000006];

vector<int>sol;



int main()

{

    fin.getline(patern,sizeof patern);

    fin.getline(s,sizeof s);

    int n=strlen(patern),m=strlen(s),i,j=0;

    for (i=1;i<n;i++)

    {

        while (j!=0 && patern[j]!=patern[i])

            j=prefix[j-1];

        if (patern[j]!=patern[i])

            prefix[i]=0;

        else {

                ++j;

                prefix[i]=j;

        }

    }

    j=0;

    for (i=0;i<m;i++)

    {

        while (j!=0 && patern[j]!=s[i])

            j=prefix[j-1];

        if (patern[j]==s[i])

            j++;

        if (j==n)

            {

                sol.push_back(i-n+1);

                j=prefix[j-1];

            }

    }

    int lg=sol.size();

    fout<<lg<<'\n';

    for (i=0;i<min(1000,lg);i++)

        fout<<sol[i]<<' ';

    return 0;

}
