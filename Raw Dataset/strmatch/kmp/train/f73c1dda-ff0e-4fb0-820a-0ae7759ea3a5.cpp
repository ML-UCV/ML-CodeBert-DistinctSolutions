#include <bits/stdc++.h>

using namespace std;

int pr[4000003];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("strmatch.in","r",stdin);
    freopen("strmatch.out","w",stdout);

    string s;
    cin>>s;
    int a=s.size();
    string aux(1,'#');
    s+='#';
    char c;
    while(cin>>c)
    {
        s+=c;
    }
    int ans=0;
    vector<int>v;
    pr[0]=-1;
    for(int i=1;i<=s.size();i++)
    {
        int k=pr[i-1];
        while(k>=0)
        {
            if(s[k]==s[i-1])
            {
                pr[i]=k+1;
                if(pr[i]==a) ans++,v.push_back(i-a*2-1);
                break;
            }
            k=pr[k];
        }
    }
    cout<<ans<<"\n";
    int kk=0;
    for(auto it:v)
    {
      kk++;
      cout<<it<<" ";
      if(kk==1000) break;
    }

}
