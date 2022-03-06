#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("swap.in");
ofstream g("swap.out");




string s1,s2;
int Aib[100666],i,N;
int a[100666],b[100666];
vector<int> H[666];
int fr1[666],fr2[666];
int grad[777],result;

int query(int pos)
{
    int res=0;
    for(; pos; pos-=(pos&(pos^(pos-1)))) res+=Aib[pos];
    return res;
}

void update(int pos,int value)
{
    for(; pos<=N; pos+=(pos&(pos^(pos-1))))
        Aib[pos]+=value;
}

int main()
{
    f>>s1>>s2;
    N=s1.length();

    for(i=0; i<N; ++i)
    {
        a[i+1]=s1[i];
        b[i+1]=s2[i];
    }

    for(i=1; i<=N; ++i)
    {
        H[b[i]].push_back(i);
        ++fr1[a[i]];
        ++fr2[b[i]];
        update(i,1);
    }

    for(i='a'; i<='z'; ++i)
        if (fr1[i]!=fr2[i])
        {
            g<<-1;
            return 0;
        }


    for(i=1; i<=N; ++i)
    {
        int _pos=H[a[i]][grad[a[i]]];
        ++grad[a[i]];
        result+=query(_pos-1);
        update(_pos,-1);
    }

    g<<result<<'\n';



    return 0;
}
