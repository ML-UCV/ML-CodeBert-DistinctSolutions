#include <bits/stdc++.h>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



int n, m;

char pattern[2000005], s[2000005];

int lps[2000005];

vector<int> sol;



void process();

void kmp();

int main()

{

    fin>>pattern>>s;

    n=strlen(s);

    m=strlen(pattern);



    process();

    kmp();



    int temp=sol.size();

    fout<<temp<<'\n';

    for(int i=0; i<min(temp, 1000); ++i)

        fout<<sol[i]<<' ';

    return 0;

}

void kmp()

{

    int i=0, j=0;

    while(i<n)

    {

        if(s[i]==pattern[j])

        {

            ++i;

            ++j;



            if(j==m)

            {

                sol.push_back(i-j);

                j=lps[j-1];

            }

        }

        else

        {

            if(j>0)

                j=lps[j-1];

            else ++i;

        }

    }

}

void process()

{

    int len=0;

    lps[0]=0;

    int i=1;



    while(i<m)

    {

        if(pattern[i]==pattern[len])

        {

            ++len;

            lps[i]=len;

            ++i;

        }

        else

        {

            if(len!=0)

                len=lps[len-1];

            else

            {

                lps[i]=0;

                ++i;

            }

        }

    }

}
