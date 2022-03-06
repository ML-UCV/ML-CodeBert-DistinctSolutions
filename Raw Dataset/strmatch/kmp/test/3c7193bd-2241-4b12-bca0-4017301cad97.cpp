#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

char pat[2000005],txt[2000005];

int n,m,i,j,len,lps[2000005],v[2000005],nr,val;

void crearelps(int n,char pat[])

{

    lps[0]=0;

    len=0;

    i=1;

    while(i<n)

    {

        if(pat[len]==pat[i])

        {

            len++;

            lps[i]=len;

            i++;

        }

        else

            if(pat[len]!=pat[i])

                {

                    if(len>0)

                    len=lps[len-1];

                    else

                        lps[i++]=0;

                }

    }

}

void kmp()

{

    crearelps(m,pat);

    i=j=0;

    while(i<n)

    {

        if(pat[j]==txt[i])

        {

            i++;

            j++;

            if(j==m)

            {

            v[++nr]=i-j;

            j=lps[j-1];

            }

        }

        else

            if(txt[i]!=pat[j]&&i<n)

        {

            if(j>0)

                j=lps[j-1];

            else

                i++;

        }

    }

}

int main()

{

    fin>>pat;

    m=strlen(pat);

    fin>>txt;

    n=strlen(txt);

    kmp();

    fout<<nr<<'\n';

    val=min(nr,1000);

    for(i=1;i<=val;i++)

        fout<<v[i]<<' ';

    return 0;

}
