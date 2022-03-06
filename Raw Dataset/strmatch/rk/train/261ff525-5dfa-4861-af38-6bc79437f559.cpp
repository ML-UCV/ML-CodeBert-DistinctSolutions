#include <fstream>
#include <vector>




using namespace std;

ifstream cin("strmatch.in");

ofstream cout("strmatch.out");

const long long lim=2e6+3;

vector<long long> sol;

int main()

{

    string a,b;

    long long na,nb,ha=0,hb=0,cnt=0,p=1;

    cin>>a>>b;

    na=a.size(),nb=b.size();

    if(na>nb)

    {

        cout<<0;

        return 0;

    }

    for(long long i=0;i<na;++i)

    {

        ha=(ha*911382323 +a[i]-48)%972663749;

        hb=(hb*911382323 +b[i]-48)%972663749;

        p=(p*911382323)%972663749;

    }

    if(ha==hb)

    {

        ++cnt;

        sol.push_back(0);

    }

    for(long long i=na;i<nb;++i)

    {

        hb=(hb*911382323 +b[i]-48)%972663749;

        hb=(hb+972663749 -(p*(b[i-na]-48))%972663749)%972663749;

        if(ha==hb)

        {

            ++cnt;

            if(cnt<=1000)

                sol.push_back(i-na+1);

        }

    }

    cout<<cnt<<'\n';

    long long nr=sol.size();

    for(long long i=0;i<nr;++i)

        cout<<sol[i]<<' ';

    return 0;

}
