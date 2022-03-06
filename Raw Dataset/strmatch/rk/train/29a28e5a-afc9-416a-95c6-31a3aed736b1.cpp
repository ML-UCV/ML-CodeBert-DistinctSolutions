#include<bits/stdc++.h>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

vector<long long>poz;

const long long MOD=1e9+7;

const long long p1=103;

long long cc(char c)

{

    if(c>='a'&&c<='z')

        return c-'a'+1;

    if(c>='A'&&c<='Z')

        return c-'A'+27;

    return c-'0'+53;

}

long long hsh(string s)

{

    long long mod=0,val=1;

    for(long long poz=(long long)s.size()-1;poz>=0;poz--)

    {

        mod=(mod+1LL*val*cc(s[poz]))%MOD;

        val=(1LL*val*p1)%MOD;

    }

    return mod;

}

int main()

{

    string a,b;

    fin>>a>>b;

    long long nr=0,hsa=hsh(a);

    string s=b.substr(0,a.size());

    long long hsb=hsh(s);

    long long put=1;

    for(long long i=1;i<=(long long)a.size();i++)

    {

        put=(1LL*put*p1)%MOD;



    }



    for(long long i=a.size();i<(long long)b.size();i++)

    {

        if(hsa==hsb)

        {

            nr++;

            if(nr<=1000)

                poz.push_back(i);

        }



        hsb=(1LL*hsb*p1+cc(b[i]))%MOD;

        hsb-=(1LL*put*(cc(b[i-a.size()])))%MOD;

        if(hsb<0)

            hsb+=MOD;

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
