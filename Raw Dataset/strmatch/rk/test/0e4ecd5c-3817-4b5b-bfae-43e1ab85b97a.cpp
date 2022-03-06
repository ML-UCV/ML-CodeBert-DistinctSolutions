#include <bits/stdc++.h>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

const int Mod1 = 1e9+7;

const int Mod2 = 1e9+9;

const int p = 131;

int main()

{

    string a,b;

    getline(f,a);

    getline(f,b);

    long long hi1=a[0]-'0',hi2=a[0]-'0',pt1=1,pt2=1,h1=0,h2=0;

    for(int i=1; i<a.size(); i++)

    {

        hi1=(hi1*p+a[i]-'0')%Mod1;

        hi2=(hi2*p+a[i]-'0')%Mod2;

        pt1=(pt1*p)%Mod1;

        pt2=(pt2*p)%Mod2;

    }

    for(int i=0; i<a.size(); i++)

    {

        h1=(h1*p+b[i]-'0')%Mod1;

        h2=(h2*p+b[i]-'0')%Mod2;

    }

    vector <int> rez;

    if(h1==hi1 && h2==hi2)

    {

        rez.push_back(0);

    }

    for(int i=a.size(); i<b.size(); i++)

    {

        h1=(1LL*(h1-(1LL*pt1*(b[i-a.size()]-'0'))%Mod1+Mod1)*p+b[i]-'0')%Mod1;

        h2=(1LL*(h2-(1LL*pt2*(b[i-a.size()]-'0'))%Mod2+Mod2)*p+b[i]-'0')%Mod2;

        if(h1==hi1 && h2==hi2)

        {

            rez.push_back(i-a.size()+1);

        }

    }

    g<<rez.size()<<'\n';

    for(int i=0;i<rez.size() && i<1000;i++)

    {

        g<<rez[i]<<' ';

    }

    return 0;

}
