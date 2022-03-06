#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>


using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

vector <int>v;

int pi[2000005];

int main()

{

    char a[2000005],b[2000005];

    fin>>a>>b;

    int n=strlen(a),m=strlen(b),i,j,k=0;

    pi[1]=0;

    for(i=2;i<=n;++i)

    {

        while(a[i-1]!=a[k] && k)k=pi[k];

        if(a[i-1]==a[k])++k;

        pi[i]=k;

    }

    k=0;

    for(i=1;i<=m;++i)

    {

        while(b[i-1]!=a[k] && k)k=pi[k];

        if(b[i-1]==a[k])++k;

        if(k==n)v.push_back(i-k);

    }

    fout<<v.size()<<'\n';

    while(v.size()>1000)v.pop_back();

    for(auto i : v)

        fout<<i<<' ';

    return 0;

}
