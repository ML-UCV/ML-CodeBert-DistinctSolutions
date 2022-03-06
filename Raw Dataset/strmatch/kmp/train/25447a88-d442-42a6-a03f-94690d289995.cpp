#include <fstream>
#include <vector>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

int stare[2000001],nr;

string s,s1;

vector <int> v;

int main()

{

    fin>>s>>s1;

    int x=s.size(),st=0,i;

    for (i=2;i<=x;i++)

    {

        while (st>0 && s[st]!=s[i-1])

            st=stare[st];

        if (s[st]==s[i-1])

            st++;

        stare[i]=st;

    }

    int x1=s1.size();

    st=0;

    for (i=1;i<=x1;i++)

    {

        while (st>0 && s[st]!=s1[i-1])

            st=stare[st];

        if (s[st]==s1[i-1])

            st++;

        if (st==x){

                nr++;

            if (nr<=1000)

                 v.push_back(i-st);

        }

    }

    fout<<nr<<"\n";

    for (auto i:v)

        fout<<i<<" ";

    return 0;

}
