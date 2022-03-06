#include<bits/stdc++.h>
using namespace std;






ifstream in("strmatch.in");
ofstream out("strmatch.out");

string text,pattern;

void read()
{
    in>>pattern>>text;
}


void rabin_karp()
{
    int base1=1,base2=1;
    long long basemod1=0,basemod2=0;

    vector<int> results;

    for(int i=0; i<pattern.length(); i++)
    {
        basemod1=(basemod1*74 +pattern[i])%100007;
        basemod2=(basemod2*74 +pattern[i])%100021;
        if(i)
        {
            base1=(base1*74)%100007;
            base2=(base2*74)%100021;
        }
    }
    long long mod1=0,mod2=0;

    for(int i=0; i<pattern.length(); i++)
    {
        char here=text[i];
        mod1=(mod1*74 +here)%100007;
        mod2=(mod2*74 +here)%100021;
    }
    if(basemod1==mod1 && basemod2==mod2)
    {
        results.push_back(0);
    }
    char last=text[0];

    for(int i=1; i<text.length()-pattern.length()+1; i++)
    {
        long long delete1=(base1*last)%100007;
        long long delete2=(base2*last)%100021;

        mod1=(((mod1-delete1+100007)*74)%100007 +text[i+pattern.length()-1])%100007;
        mod2=(((mod2-delete2+100021)*74)%100021 +text[i+pattern.length()-1])%100021;

        if(mod1==basemod1 && mod2==basemod2)
        {
            results.push_back(i);
        }
        last=text[i];
    }

    out<<results.size()<<endl;
    int ending=results.size();
    ending=min(ending,1000);
    for(int i=0; i<ending; i++)
    {
        out<<results[i]<<" ";
    }


}



int main()
{
    read();
    if(pattern.length()>text.length())
        out<<0;
    else
        rabin_karp();
}
