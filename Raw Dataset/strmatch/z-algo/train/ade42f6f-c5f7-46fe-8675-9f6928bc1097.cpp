#include <bits/stdc++.h>
using namespace std;

ifstream in("strmatch.in");

ofstream out("strmatch.out");

int main()

{

    string a,b;

    in>>a>>b;

    int n,k;

    k=a.size();

    a+='#'+b;

    n=a.size();

    vector<int> z(n),sol;

    int x=0,y=0,ans=0;

    for(int i=1;i<n;++i)

    {

        z[i]=max(0,min(z[i-x],y-i+1));

        while(i+z[i]<n and a[z[i]]==a[i+z[i]])

            x=i,y=i+z[i],z[i]++;

        if(i>k and z[i]==k)

        {

            ++ans;

            if(ans<=1000)

                sol.push_back(i-k-1);

        }

    }

    out<<ans<<'\n';

    for(int x:sol)

        out<<x<<' ';

    return 0;

}
