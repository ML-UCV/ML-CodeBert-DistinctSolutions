#include <fstream>
#include <vector>
using namespace std;

ifstream cin("strmatch.in");

ofstream cout("strmatch.out");

vector<int> z_algo(string s)

{

    int n=s.size();

    vector<int> z(n);

    int x=0,y=0;

    for(int i=1;i<n;i++)

    {

        z[i]=max(0,min(z[i-x],y-i+1));

        while(i+z[i]<n and s[z[i]]==s[i+z[i]])

        {

            x=i;

            y=i+z[i];

            z[i]++;

        }

    }

    return z;

}

vector<int> sol;

int main()

{

    string a,b,s;

    cin>>a>>b;

    s=a+'#'+b;

    vector<int> v=z_algo(s);

    int cnt=0;

    for(int i=a.size()+1;i<s.size();++i)

    if(v[i]==a.size())

    {

        ++cnt;

        if(cnt<=1000)

            sol.push_back(i-a.size()-1);

    }

    cout<<cnt<<'\n';

    for(int i=0;i<sol.size();++i)

        cout<<sol[i]<<' ';

    return 0;

}
