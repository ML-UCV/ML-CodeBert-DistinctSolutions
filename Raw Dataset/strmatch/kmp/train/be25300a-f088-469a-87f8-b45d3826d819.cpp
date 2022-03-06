#include <bits/stdc++.h>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

string a,b;

int pi[4000005];

void kmp(string s)

{

    pi[0]=0;

    int j=0;

    for(int i=1;i<s.size();i++)

    {

        while(j && s[i]!=s[j])

        {

            j=pi[j-1];

        }

        if(s[i]==s[j])

        {

            ++j;

        }

        pi[i]=j;

    }

    vector <int> rez;

    for(int i=a.size()+1;i<s.size();i++)

    {

        if(pi[i]==a.size())

        {

            rez.push_back(i-a.size()-pi[i]);

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

    kmp(a+'#'+b);

    return 0;

}
