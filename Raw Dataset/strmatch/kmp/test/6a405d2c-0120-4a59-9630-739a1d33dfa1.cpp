#include <bits/stdc++.h>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

string s,s1;

int v[4000005],n,i,k,numar,urm[4000005],valoare,lim;

vector <int> sol;

int main()

{

    f>>s;

    n=s.size();

    f>>s1;

    s=s+'#'+s1;

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

        if (k==n)

        {

            numar++;

            sol.push_back(i-2*n);

        }

    }

    g<<numar<<'\n';

    valoare=sol.size();

    lim=min(valoare,1000);

    for (i=0;i<lim;i++)

    {

        g<<sol[i]<<" ";

    }

    return 0;

}
