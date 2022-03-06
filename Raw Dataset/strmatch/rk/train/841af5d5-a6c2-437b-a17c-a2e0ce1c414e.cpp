#include <bits/stdc++.h>


const int mod=1000000007;



const int prim=666013;



using namespace std;



string str1,str2;



unsigned int nr;



queue <int> ans;



int main()

{

    ifstream fin ("strmatch.in");

    ofstream fout ("strmatch.out");

    fin>>str1>>str2;

    if (str1.length()>str2.length())

    {

        fout<<0;

        return 0;

    }

    int_fast64_t ct=1,hash1=0,chash=0;

    for (int i=1;i<str1.length();++i)

    {

        ct*=prim;

        ct%=mod;

    }

    for (int i=0;i<str1.length();++i)

    {

        hash1=hash1*prim+str1[i];

        hash1=hash1%mod;

        chash=chash*prim+str2[i];

        chash%=mod;

    }



    if (chash==hash1)

    {

        ans.push(0);

        nr++;

    }

    for (int i=str1.length();i<str2.length();++i)

    {

        chash=chash-ct*str2[i-str1.length()];

        chash=chash%mod;

        chash=chash*prim+str2[i];

        chash=chash%mod;

        if (chash<0)

        {

            chash+=mod;

        }

        if (chash==hash1)

        {

            ans.push(i-str1.length()+1);

            nr++;

        }



    }

    fout<<nr<<"\n";

    int out=0;

    while (!ans.empty())

    {

        fout<<ans.front()<<" ";

        ans.pop();

        out++;

        if (out==1000)

        {

            break;

        }

    }

    return 0;

}
