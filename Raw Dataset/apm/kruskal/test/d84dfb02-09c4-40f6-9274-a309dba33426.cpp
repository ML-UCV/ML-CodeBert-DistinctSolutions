#include<fstream>
#include<algorithm>
using namespace std;

ifstream cin("apm.in");

ofstream cout("apm.out");

struct ura

{

    int nr1;

    int nr2;

    int c;

};

int sef[200001];

ura v[400001];

pair<int, int> raspuns[200000];

int sefsuprem(int nod)

{

    if(sef[nod]==nod)

        return nod;

    else

        return sef[nod]=sefsuprem(sef[nod]);

}

void unire(int nod1, int nod2)

{

    int sef1, sef2;

    sef1=sefsuprem(nod1);

    sef2=sefsuprem(nod2);

    sef[sef2]=sef1;

}

bool cmp(ura a, ura b)

{

    return a.c < b.c;

}

int main()

{

    int n, m, sef1, sef2, k, s;

    cin>>n>>m;

    for(int i=1; i<=n; i++)

        sef[i]=i;

    for(int i=1; i<=m; i++)

    {

        cin>>v[i].nr1>>v[i].nr2>>v[i].c;

    }

    sort(v+1, v+m+1, cmp);

    k=n;

    s=0;

    for(int i=1; i<=m && k>0; i++)

    {

        sef1=sefsuprem(v[i].nr1);

        sef2=sefsuprem(v[i].nr2);

        if(sef1 != sef2)

        {

            k--;

            s+=v[i].c;

            unire(v[i].nr1, v[i].nr2);

            raspuns[n-k].first=v[i].nr1;

            raspuns[n-k].second=v[i].nr2;

        }

    }

    cout<<s<<'\n'<<n-1<<'\n';

    for(int i=1; i<n; i++)

        cout<<raspuns[i].first<<" "<<raspuns[i].second<<'\n';

    return 0;

}
