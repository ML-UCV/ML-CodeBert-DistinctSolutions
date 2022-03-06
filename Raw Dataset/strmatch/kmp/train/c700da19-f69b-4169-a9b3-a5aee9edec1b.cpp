#include <bits/stdc++.h>


using namespace std;

ifstream fin("strmatch.in");

ofstream fout ("strmatch.out");

int n,m,i,q,j,nr;

string s,t;

vector <int> ans;

int pi[2000005];

int main()

{

    fin>>t;

    n=t.size();



    pi[0]=0;

    for(i=1;i<n;i++)

    {

        int j=pi[i-1];

        while(j>0 && t[i]!=t[j])

            j=pi[j-1];



        if(t[j]==t[i])

            j++;



        pi[i]=j;

    }



    fin>>s;

    m=s.size();

    q=0;



    for(i=0;i<m;i++)

    {

        while(q>0 && t[q]!=s[i])

            q=pi[q-1];



        if(t[q]==s[i])

            q++;



        if(q==n)

        {

            nr++;

            if(ans.size()<1000)

                ans.push_back(i-n+1);

        }



    }



    fout<<nr<<'\n';

    for(int it : ans)

        fout<<it<<' ';

    return 0;

}
