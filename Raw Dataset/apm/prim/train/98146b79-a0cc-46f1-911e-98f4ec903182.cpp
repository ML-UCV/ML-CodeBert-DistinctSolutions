#include <bits/stdc++.h>


using namespace std;



struct ura{

    int nod,c;

    bool operator <(const ura &other)const{

        return c<other.c;

    }

};

vector<ura> v[200001];

multiset<ura> s;

int cost[200001],parc[200001],cor[200001];

ura ans[200001];



void apm(int nodadaug){

    int i,x,cs;

    ura nod;

    for(i=0;i<v[nodadaug].size();++i){

        x=v[nodadaug][i].nod;

        cs=v[nodadaug][i].c;

        if(cost[x]>cs){

            cor[x]=nodadaug;

            cost[x]=cs;

            s.insert(v[nodadaug][i]);

        }

    }

}



int main()

{

    ifstream cin("apm.in");

    ofstream cout("apm.out");



    int n,m,x,y,cs,i,costmin;

    cin>>n>>m;

    ura nod;

    for(i=1;i<=m;++i){

        cin>>x>>y>>cs;

        nod.nod=y;

        nod.c=cs;

        v[x].push_back(nod);

        nod.nod=x;

        v[y].push_back(nod);

    }

    for(i=1;i<=n;++i)

        cost[i]=2e9;

    apm(1);

    parc[1]=1;

    costmin=0;

    int nod1;

    for(i=2;i<=n;++i){

        nod1=s.begin()->nod;

        while(parc[nod1]==1){

            s.erase(s.begin());

            nod1=s.begin()->nod;

        }

        if(s.size()>0)

            s.erase(s.begin());

        parc[nod1]=1;

        apm(nod1);

        costmin+=cost[nod1];

        nod.nod=nod1;

        nod.c=cor[nod1];

        ans[i]=nod;

    }

    cout<<costmin<<'\n'<<n-1<<'\n';

    for(i=2;i<=n;++i){

        cout<<ans[i].c<<" "<<ans[i].nod<<'\n';

    }

    return 0;

}
