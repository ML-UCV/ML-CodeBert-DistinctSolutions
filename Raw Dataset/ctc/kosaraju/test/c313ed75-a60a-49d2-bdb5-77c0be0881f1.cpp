#include <bits/stdc++.h>
using namespace std;

ifstream r("ctc.in");

ofstream w("ctc.out");

int d[100001],n,o,nr,m;

bool v[100001];

vector <int> a[100001],a2[100001],c[100001];

void f(int x)

{

    if(!v[x])

    {

        v[x]=1;

        for(int t : a[x])

            f(t);

        d[++nr]=x;

    }

}

void g(int x)

{

    if(v[x])

    {

        v[x]=0;

        for(int t : a2[x])

            g(t);

        c[o].push_back(x);

    }

}

int main()

{

    r>>n>>m;

    int x,y;

    while(r>>x>>y){

        a[x].push_back(y);

        a2[y].push_back(x);

    }

    for(int i=1; i<=n; i++){

        f(i);

    }

    for(int i=n; i>=1; i--){

        if(v[d[i]])

        {

            o++;

            g(d[i]);

        }

    }

    w<<o<<"\n";

    for(int i=1; i<=o; i++)

    {

        for(int t : c[i]){

            w<<t<<" ";

        }

        w<<"\n";

    }

    return 0;

}
