#include <bits/stdc++.h>

using namespace std;

ifstream in;
ofstream out;

string pat,s;
vector<int> ap,sol;

void pattern()
{
    ap.push_back(0);
    int z=1;
    while(z<pat.size())
    {
        if(pat[z]==pat[0])
        {
            int d1=0,nr=1;
            while (z<pat.size() and pat[z]==pat[d1])
            {
                ap.push_back(nr);
                nr++;
                z++;
                d1++;
            }

        }
        else
        {
            ap.push_back(0);
            z++;
        }
    }
}

void KMP()
{
    int n=s.size();
    int j=0, i=0;
    while (j<n)
    {
        if(s[j]==pat[i])
        {

                i++;
                j++;
        }
        if(i==pat.size())
        {
            sol.push_back(j-i);
            i=ap[i-1];
        }
        else if(j<n and pat[i]!=s[j])
        {
            if(i!=0)
                i=ap[i-1];
            else
                j++;
        }
    }
}

int main()
{
    in.open("strmatch.in");
    out.open("strmatch.out");

    in>>pat>>s;
    pattern();
    KMP();
    int k;
    if(1000>sol.size())
        k=sol.size();
    else
        k=1000;
    out<<sol.size()<<endl;
    for(int i=0;i<k;i++)
        out<<sol[i]<<" ";
    return 0;
}
