#include <bits/stdc++.h>


using namespace std;



struct ura{

    int nod1,nod2,cost;

};

ura v[400001],ans[400001];

bool ord(ura a,ura b){

    if(a.cost!=b.cost)

        return a.cost<b.cost;

    if(a.nod1!=b.nod1)

        return a.nod1<b.nod1;

    return a.nod2<b.nod2;

}

int sef[200001];



int sefsuprem(int x){

    if(sef[x]==x)

        return x;

    else

        return sef[x]=sefsuprem(sef[x]);

}



void unire(int x,int y){

    int sefx=sefsuprem(x);

    int sefy=sefsuprem(y);

    sef[sefx]=sefy;

}



int main()

{

    ifstream cin("apm.in");

    ofstream cout("apm.out");



    int i,nr_muchii,costmin,n,m;

    cin>>n>>m;

    for(i=1;i<=n;++i)

        sef[i]=i;

    for(i=1;i<=m;++i)

        cin>>v[i].nod1>>v[i].nod2>>v[i].cost;

    sort(v+1,v+m+1,ord);

    nr_muchii=0;

    costmin=0;

    for(i=1;i<=m && nr_muchii<n-1;++i){

        if(sefsuprem(v[i].nod1)!=sefsuprem(v[i].nod2)){

            unire(v[i].nod1,v[i].nod2);

            costmin+=v[i].cost;

            ++nr_muchii;

            ans[nr_muchii]=v[i];

        }

    }

    cout<<costmin<<'\n'<<nr_muchii<<'\n';

    for(i=1;i<=nr_muchii;++i)

        cout<<ans[i].nod2<<" "<<ans[i].nod1<<'\n';

    return 0;

}
