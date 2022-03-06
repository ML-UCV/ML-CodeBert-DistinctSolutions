#include<bits/stdc++.h>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

vector<int>poz;

const int MOD1=1e9+7;

const int p1=131;

const int MOD2=1e9+9;

const int p2=135;

pair < int, int > hsh(string s)

{

    int mod1=0,mod2=0,val1=1,val2=1;

    for(int poz=(int)s.size()-1;poz>=0;poz--)

    {

        mod1=(mod1+1LL*val1*(s[poz]-'0'))%MOD1;

        mod2=(mod2+1LL*val2*(s[poz]-'0'))%MOD2;

        val1=(1LL*val1*p1)%MOD1;

        val2=(1LL*val2*p2)%MOD2;

    }

    return {mod1, mod2};

}



int main()

{

    string a,b;

    fin>>a>>b;

    int nr=0;

    pair < int, int > hsa=hsh(a);

    string s=b.substr(0,a.size());

    pair < int, int > hsb=hsh(s);

    int put1=1, put2=1;

    for(int i=1;i<=(int)a.size();i++)

    {

        put1=(1LL*put1*p1)%MOD1;

        put2=(1LL*put2*p2)%MOD2;

    }

    for(int i=a.size();i<(int)b.size();i++)

    {

        if(hsa==hsb)

        {

            nr++;

            if(nr<=1000)

                poz.push_back(i);

        }

        hsb.first=(1LL*hsb.first*p1+b[i]-'0')%MOD1;

        hsb.second=(1LL*hsb.second*p2+b[i]-'0')%MOD2;

        hsb.first-=(1LL*put1*(b[i-a.size()]-'0'))%MOD1;

        hsb.second-=(1LL*put2*(b[i-a.size()]-'0'))%MOD2;

        if(hsb.first<0)

            hsb.first+=MOD1;

        if(hsb.second<0)

            hsb.second+=MOD2;

    }

    if(hsa==hsb)

    {

        nr++;

        if(nr<=1000)

            poz.push_back(b.size());

    }

    fout<<nr<<"\n";

    for(auto p:poz)

        fout<<p-a.size()<<" ";

}
