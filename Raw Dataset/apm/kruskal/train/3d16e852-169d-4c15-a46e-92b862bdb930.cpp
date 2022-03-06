#include<bits/stdc++.h>




using namespace std;

const int DN=1e6+5;

int n,m,pr[DN];

pair<int,pair<int,int> >mc[DN];

priority_queue<pair<int,int> >pq;

vector<pair<int,int> >sol;



long long sum;



int getpr(int nod)

{

    if(pr[nod]==nod)

        return nod;

    pr[nod]=getpr(pr[nod]);

    return pr[nod];

}





void unesc(int f,int g,int cost)

{

    int p1=getpr(f);

    int p2=getpr(g);

    cout<<f<<' '<<g<<'\n';

    if(p1==p2)

        return;

    pr[p1]=p2;

    sol.push_back({f,g});

    sum+=cost;

}

int main()

{

    FILE *fin=fopen("apm.in","r");

    FILE *fout=fopen("apm.out","w");



    fscanf(fin,"%d%d",&n,&m);

    for(int i=1;i<=m;i++)

        fscanf(fin,"%d%d%d",&mc[i].second.first,&mc[i].second.second,&mc[i].first);



    for(int i=1;i<=n;i++)

        pr[i]=i;



    sort(mc+1,mc+m+1);

    for(int pz=1;pz<=m;pz++)

    {

        int f=mc[pz].second.first;

        int g=mc[pz].second.second;

        cout<<f<<' '<<g<<'\n';

        unesc(f,g,mc[pz].first);

    }

    fprintf(fout,"%d\n",sum);

    fprintf(fout,"%d\n",(int)sol.size());

    for(auto i:sol)

        fprintf(fout,"%d %d\n",i.first,i.second);



}
