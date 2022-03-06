#include<bits/stdc++.h>


using namespace std;



ifstream fin("strmatch.in");



ofstream fout("strmatch.out");



vector<int>poz;



const int MOD=1e9+7;



const int p1=131;







int hsh(string s)



{



    int mod=0,val=1;



    for(int poz=(int)s.size()-1;poz>=0;poz--)



    {



        mod=(mod+1LL*val*(s[poz]-'0'))%MOD;



        val=(1LL*val*p1)%MOD;



    }



    return mod;



}







int main()



{



    string a,b;



    fin>>a>>b;



    int nr=0,hsa=hsh(a);



    string s=b.substr(0,a.size());



    int hsb=hsh(s);



    int put=1;



    for(int i=1;i<=(int)a.size();i++)



    {



        put=(1LL*put*p1)%MOD;



    }



    for(int i=a.size();i<(int)b.size();i++)



    {



        if(hsa==hsb)



        {



            nr++;



            if(nr<=1000)



                poz.push_back(i);



        }



        hsb=(1LL*hsb*p1+b[i]-'0')%MOD;



        hsb-=(1LL*put*(b[i-a.size()]-'0'))%MOD;



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
