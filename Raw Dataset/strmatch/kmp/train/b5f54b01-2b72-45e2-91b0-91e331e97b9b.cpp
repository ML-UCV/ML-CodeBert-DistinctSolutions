#include <fstream>
#include <vector>


using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

string s,s1;

int stare[2000005],nr;

vector <int> v;

int main()

{

    int i;

    fin>>s>>s1;

    int st=0;

    int x=s.size();

    for (i=2;i<=x;i++)

    {

        while (st>0 && s[i-1]!=s[st])

            st=stare[st];

        if (s[i-1]==s[st])

            st++;

        stare[i]=st;

    }

    int x1=s1.size();

    st=0;

    for (i=1;i<=x1;i++)

    {

         while (st>0 && s1[i-1]!=s[st])

            st=stare[st];

        if (s1[i-1]==s[st])

            st++;

        if (st>=x)

        {

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
