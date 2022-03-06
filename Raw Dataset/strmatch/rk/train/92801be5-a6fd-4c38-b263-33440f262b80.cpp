#include <fstream>
#include <string>
#include <vector>






using namespace std;

ifstream cin("strmatch.in");

ofstream cout("strmatch.out");

long long int x1=1,x2=1,mod,H1,H2,h1,h2;

vector<int>v;

string a,b;

void logpow(long long int &oof,long long int exp,long long int mod)

{

    long long int rez=1,okei=oof;

    while(exp)

    {

        if(exp%2==1)

        rez*=okei;

        rez%=mod;

        okei*=okei;

        okei%=mod;

        exp/=2;

    }

    oof=rez;

}

void afis(vector<int> v)

{

    cout<<v.size()<<'\n';

    for(int i=0;i<1000&&i<v.size();i++)

        cout<<v[i]<<' ';

}

int main()

{

    cin>>a>>b;

    for(int i=0;i<a.size();i++)

    {

        H1+=(a[a.size()-i-1]-'0'+1)*x1;

        H2+=(a[a.size()-i-1]-'0'+1)*x2;

        x1*=97;

        x2*=97;

        H1%=1000000007;

        H2%=1000000009;

        x1%=1000000007;

        x2%=1000000009;

    }

    x1=x2=1;

    for(int i=0;i<a.size();i++)

    {

        h1+=(b[a.size()-i-1]-'0'+1)*x1;

        h2+=(b[a.size()-i-1]-'0'+1)*x2;

        x1*=97;

        x2*=97;

        h1%=1000000007;

        h2%=1000000009;

        x1%=1000000007;

        x2%=1000000009;

    }

    long long int l=a.size()-1;

    x1=x2=97;

    logpow(x1,l,1000000007);

    logpow(x2,l,1000000009);

    if(h1==H1&&h2==H2)

        v.push_back(0);

    for(int i=a.size();i<b.size();i++)

    {

        h1+=1000000007;

        h1-=(b[i-a.size()]-'0'+1)*x1;

        h1%=1000000007;

        h1*=97;

        h1%=1000000007;

        h1+=b[i]-'0'+1;

        h1%=1000000007;

        h2+=1000000009;

        h2-=(b[i-a.size()]-'0'+1)*x2;

        h2%=1000000009;

        h2*=97;

        h2%=1000000009;

        h2+=b[i]-'0'+1;

        h2%=1000000009;

        if(h1<0)

            h1+=1000000007;

        if(h2<0)

            h2+=1000000009;

        if(h1==H1&&h2==H2)

            v.push_back(i-a.size()+1);

    }

    afis(v);

    return 0;

}
