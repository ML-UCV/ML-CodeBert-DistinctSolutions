#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

char s1[2000009],s2[2000009];

int prefix[2000009],ans[1009],k,j;

int main()

{

        fin.getline(s1,2000005);

        fin.getline(s2,2000005);

        int n=strlen(s1);

        int m=strlen(s2);

    j=0;

    for(int i=1;i<n;i++)

    {

        while(s1[j]!=s1[i]&&j!=0)

            j=prefix[j-1];

        if(s1[i]==s1[j])

            j++;

        prefix[i]=j;

    }

    prefix[0]=0;

    j=0;

    for(int i=0;i<m;i++)

    {

        while(s1[j]!=s2[i]&&j!=0)

                j=prefix[j-1];

        if(s1[j]==s2[i])

         {

             j++;

            if(j==n)

            {

                k++;

                if(k<=1000)

                    ans[k]=i-j+1;

                j=prefix[j-1];

            }

         }

    }

        fout<<k<<'\n';

    int marime=min(1000,k);

    for(int i=1;i<=marime;i++)

        fout<<ans[i]<<' ';

}
