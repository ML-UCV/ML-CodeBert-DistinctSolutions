#include <bits/stdc++.h>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

string a,b;

int z[4000005];

void z_algorithm(string s)

{

    for(int i=1,l=0,r=0;i<s.size();i++)

    {

        if(i<=r)

        {

            z[i]=min(z[i-l],r-i+1);

        }

        while(i+z[i]-1<s.size() && s[z[i]]==s[i+z[i]])

        {

            z[i]++;

        }

        if(i+z[i]-1>r)

        {

            l=i;

            r=i+z[i]-1;

        }

    }

    vector <int> rez;

    for(int i=a.size()+1;i<s.size();i++)

    {

        if(z[i]==a.size())

        {

            rez.push_back(i-a.size()-1);

        }

    }

    g<<rez.size()<<'\n';

    for(int i=0;i<rez.size() && i<1000;i++)

    {

        g<<rez[i]<<' ';

    }

    g<<'\n';

}

int main()

{

    getline(f,a);

    getline(f,b);

    z_algorithm(a+'#'+b);

    return 0;

}
