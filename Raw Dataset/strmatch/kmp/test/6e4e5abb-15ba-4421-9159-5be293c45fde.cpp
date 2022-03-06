#include<bits/stdc++.h>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

int n, m;

string a, b;

vector<int>ans;

int q;

int pi[2000011];

void prefix()

{

    for(int i=2; i<n; i++)

    {

        while(q && a[q+1]!=a[i])

            q=pi[q];

        if(a[q+1]==a[i])

            q++;

        pi[i]=q;

    }

}

int main()

{

    f>>a;

    f>>b;

    a=' '+a;

    b=' '+b;

    n=a.size();

    m=b.size();

    prefix();

    q=0;

    for(int i=1; i<m; i++)

    {

        while(q && a[q+1]!=b[i])

            q=pi[q];

        if(a[q+1]==b[i])

            q++;

        if(q==n-1)

        {

            q=pi[n-1];

            ans.push_back(i-n+1);

        }

    }

    g<<ans.size()<<'\n';

    for(int i=0; i<ans.size(); i++)

    {

        g<<ans[i]<<' ';

        if(i==999)

            return 0;

    }

    return 0;

}
