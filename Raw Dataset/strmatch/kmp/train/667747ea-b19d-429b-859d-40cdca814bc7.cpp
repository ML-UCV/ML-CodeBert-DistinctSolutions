#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

char a[2000001];

char b[2000001];

int n;

int pi[2000001];

int sol[1000];

int nrsol;
int main()

{

    f>>a>>b;

    f.close();

    int i,j;

    pi[0]=0;

    j=0;

    i=1;

    while(a[i])

    {

        if(a[i]==a[j])

        {

            pi[i]=j+1;

            i++;

            j++;

        }

        else if(j==0)

            pi[i++]=0;

        else

            j=pi[j-1];

    }

    n=i;

    i=j=0;
    while(b[j])

    {

        if(a[i]==b[j])

        {

            i++;

            j++;

            if(!a[i])

            {



                if(nrsol<1000)

                    sol[nrsol]=j-n;

                nrsol++;
            }

        }

        else if(i==0)

            j++;

        else

            i=pi[i-1];

    }

    g<<nrsol<<'\n';

    nrsol=min(1000,nrsol);

    for(i=0;i<nrsol;i++)

        g<<sol[i]<<' ';

    return 0;
}
