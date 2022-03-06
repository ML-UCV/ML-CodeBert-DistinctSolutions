#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");

pair<int,int>w[100002];

int n,i,v[100002],k,a[100002];

unsigned long long sol;

int query(int p)

{

    int s=0;

    for(;p;p-=p&(-p))

    {

        s+=a[p];

    }

    return s;

}



void update(int p)

{

    for(;p<=k;p+=p&(-p))

        a[p]++;

    return;

}

int main()

{

    fin>>n;

    for(i=1; i<=n; i++)

    {

        fin>>w[i].first;

        v[i]=w[i].first;

        w[i].second=i;

    }

    sort(w+1,w+n+1);

    w[0].first=2000000000;

    for(i=1; i<=n; i++){

        if(w[i].first!=w[i-1].first) k++;

        v[w[i].second]=k;

    }



    for(i=1; i<=n; i++){

        sol+=(query(k)-query(v[i]));

        update(v[i]);

    }

    fout<<sol%9917;

}
