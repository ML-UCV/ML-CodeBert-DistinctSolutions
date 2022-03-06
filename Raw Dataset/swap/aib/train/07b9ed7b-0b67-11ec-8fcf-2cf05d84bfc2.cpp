#include <iostream>
#include<vector>
#include<fstream>
using namespace std;

int aib[50005],sum,poz,i,n,x,nr,ind[28];

long long tot,summ;

vector<int> v[29];

string s1,s2;

inline int lbit(int x)

{

    return ((x^(x-1))&x);

}

void update(int y,int val)

{

    for(poz=y;poz<=n;poz+=lbit(poz))

        aib[poz]+=val;

}

int compute(int y)

{

    sum=0;

    for(poz=y;poz>0;poz-=lbit(poz))

        sum+=aib[poz];

    return sum;

}

int main()

{

    ifstream f("swap.in");

    ofstream g("swap.out");

    f>>s1>>s2;

    if(s1.size()!=s2.size()) {g<<"-1";return 0;}

    n=s1.size();

    for(i=0;i<s1.size();i++)

    {

        v[s1[i]-'a'].push_back(i);

    }

    for(i=1;i<=n;i++)

        update(i,1);

    for(i=0;i<s2.size();i++)

    {

        nr=s2[i]-'a';

        if(ind[nr]+1>v[nr].size()) {g<<"-1";return 0;}

        else

        {

           x=v[nr][ind[nr]];

           summ=compute(x+1)-(i+1);

           tot+=summ;

           update(1,1);

           update(x+1,-1);

           ind[nr]++;

        }

    }

    g<<tot;

    return 0;

}
