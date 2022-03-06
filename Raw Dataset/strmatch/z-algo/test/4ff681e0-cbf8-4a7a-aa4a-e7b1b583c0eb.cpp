#include <bits/stdc++.h>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

string s,s1;

int n,i,k,numar,valoare,lim,l,r,z[4000005];

vector <int> sol;

int main()

{

    f>>s;

    n=s.size();

    f>>s1;

    s=s+'#'+s1;

    l=r=0;

    for (i=1;i<s.size();i++)

    {

        if (i<=r)

        {

            z[i]=min(z[i-l],r-i+1);

        }

        while (i+z[i]<s.size()&&s[z[i]]==s[i+z[i]])

        {

            z[i]++;

        }

        if (i+z[i]-1>r)

        {

            r=i+z[i]-1;

            l=i;

        }

        if (z[i]==n)

        {

            numar++;

            sol.push_back(i-n-1);

        }

    }

    g<<numar<<'\n';

    for (i=0;i<min(numar,1000);i++)

    {

        g<<sol[i]<<" ";

    }

    return 0;

}
