#include <fstream>
#include <vector>
using namespace std;

ifstream cin("strmatch.in");

ofstream cout("strmatch.out");

vector<long long> sol;

const long long A=914530549;

const long long B=914531357;

int main()

{

    long long rasp=0;

    string a,b;

    cin>>a>>b;

    if(a.size()>b.size())

    {

        cout<<0<<'\n';

        return 0;

    }

    long long n=a.size(),ka=0,kb=0,power=1;

    for(long long i=0;i<n;++i)

    {

        ka=(ka*A+a[i])%B;

        power=(power*A)%B;

    }

    for(long long i=0;i<n;++i)

        kb=(kb*A+b[i])%B;

    if(ka==kb) ++rasp,sol.push_back(0);

    for(long long i=1;i<=b.size()-n;++i)

    {

        kb=(kb*A+b[i+n-1])%B;

        kb=(kb-(power*(b[i-1]))%B+B)%B;

        if(ka==kb)

        {

            ++rasp;

            if(sol.size()<1000)

                sol.push_back(i);

        }

    }

    cout<<rasp<<'\n';

    for(long long i=0;i<sol.size();++i)

        cout<<sol[i]<<' ';

    return 0;

}
