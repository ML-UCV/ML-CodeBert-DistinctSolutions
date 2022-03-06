#include <fstream>
#include <cstring>
using namespace std;

ifstream in("strmatch.in");

ofstream out("strmatch.out");

string s1,s2,s;

int afis[1001],pi[4000001];

int main()

{

    int i,cnt=0;

    in>>s1>>s2;

    s=" "+s1+"#"+s2;

    for(i=2; i<s.size(); i++)

    {

        pi[i]=pi[i-1];

        while(pi[i]&&s[pi[i]+1]!=s[i])

            pi[i]=pi[pi[i]];

        if(s[pi[i]+1]==s[i])

            pi[i]++;

        if(i>s1.size()+1&&pi[i]==s1.size())

        {

            cnt++;

            if(cnt<=1000)

                afis[cnt]=i-2*s1.size()-1;

        }

    }

    out<<cnt<<'\n';

    for(i=1; i<=min(cnt,1000); i++)

        out<<afis[i]<<" ";

    return 0;

}
