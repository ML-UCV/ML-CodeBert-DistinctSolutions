#include <bits/stdc++.h>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

string a,b,s;

int urm[4000005],k,i,sol[4000005],numar;

int main()

{

    f>>a;

    f>>b;

    s=a+'#'+b;

    urm[0]=0;

    k=0;

    for (i=1;i<s.size();i++)

    {

        while (k>0&&s[i]!=s[k])

        {

            k=urm[k-1];

        }

        if (s[i]==s[k])

        {

            k++;

        }

        urm[i]=k;

        if (urm[i]==a.size()&&i>a.size())

        {

            sol[++numar]=i;

        }

    }

    g<<numar<<'\n';

    for (i=1;i<=numar&&i<=1000;i++)

    {

        g<<sol[i]-2*a.size()<<" ";

    }

    return 0;

}
