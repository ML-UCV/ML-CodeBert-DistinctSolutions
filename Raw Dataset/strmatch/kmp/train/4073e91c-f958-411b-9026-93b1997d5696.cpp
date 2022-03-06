#include<bits/stdc++.h>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

string a,b;

int pi[4000001],nr;

vector<int>sol;

int main()

{

    fin>>a>>b;

    int s=a.size();

    a=a+"*"+b;

    for(int i=1;i<(int)a.size();i++)

    {

        if(a[pi[i-1]]==a[i])

        {

            pi[i]=pi[i-1]+1;

        }

        else

        {

            if(pi[i-1]==0)

                continue;

            int j=pi[pi[i-1]-1];

            while(j>0&&a[j]!=a[i])

            {

                j=pi[j-1];

            }

            if(j==0&&a[j]==a[i])

                pi[i]=1;

            else if(j==0)

                pi[i]=0;

            else pi[i]=j+1;

        }

        if(pi[i]==s)

            {

                if(sol.size()<1000)

                    sol.push_back(i-s*2);

                nr++;

            }

    }

    fout<<nr<<"\n";

    for(auto p:sol)

        fout<<p<<" ";

}
