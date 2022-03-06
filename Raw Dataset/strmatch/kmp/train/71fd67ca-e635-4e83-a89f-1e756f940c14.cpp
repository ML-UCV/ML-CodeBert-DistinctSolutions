#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

char sir[2000005],s[2000005];

int l[2000005],v[1010];

int main()

{

    int i,j,n,numar=0,poz,m;

    fin>>s>>sir;

    n=strlen(s)-1;

    i=1;

    j=0;

    while(i<=n)

    {

        if(s[i]==s[j])

            l[i]=j+1,i++,j++;

        else

        {

            while(j>0&&s[j]!=s[i])

                j=l[j-1];

            if(s[j]==s[i])

                l[i]=j+1,i++,j++;

            else

                if(s[i]!=s[j]&&j==0)

                    l[i]=0,i++;

        }

    }

    i=0;

    j=0;

    m=strlen(sir)-1;

    while(j<=m)

    {

        if(s[i]==sir[j])

        {

             poz=j-i;

             while(s[i]==sir[j]&&i<=n)

                i++,j++;

            if(i==n+1)

                if(numar>=1000)

                    numar++;

                else

                    v[++numar]=poz;

            i=l[i-1];

        }

        else

            {

                while(s[i]!=sir[j]&&i>0)

                    i=l[i-1];

                if(i==0&&s[i]!=sir[j])

                    j++;

            }

    }

    fout<<numar<<'\n';

    if(numar>1000)

    for(i=1;i<=1000;i++)

        fout<<v[i]<<' ';

    else

        for(i=1;i<=numar;i++)

            fout<<v[i]<<' ';

    return 0;

}
