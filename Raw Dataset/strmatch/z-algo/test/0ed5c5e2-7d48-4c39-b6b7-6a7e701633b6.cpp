#include <fstream>
#include <vector>
using namespace std;

ifstream cin("strmatch.in");

ofstream cout("strmatch.out");

vector<int> sol;

vector<int> zzz(string s)

{

    int l,r,n=s.size();

    vector<int> z(n);

    l=r=0;

    for(int i=1;i<n;++i)

    {

        if(i>r)

        {

            l=r=i;

            while(r<n and s[r-l]==s[r]) ++r;

            z[i]=r-l;

            --r;

        }

        else

        {

            int k=i-l;

            if(z[k]<r-i+1) z[i]=z[k];

            else

            {

                l=i;

                while(r<n and s[r-l]==s[r]) ++r;

                z[i]=r-l;

                --r;

            }

        }

    }

    return z;

}

int main()

{

    string pat,txt;

    int answer=0;

    cin>>pat>>txt;

    txt=pat+'#'+txt;

    vector<int> poz=zzz(txt);

    for(int i=pat.size()+1;i<txt.size();++i)

    if(poz[i]==pat.size())

    {

        ++answer;

        if(sol.size()<1000)

            sol.push_back(i-pat.size()-1);

    }

    cout<<answer<<'\n';

    for(int i=0;i<sol.size();++i)

        cout<<sol[i]<<' ';

    return 0;

}
