#include<bits/stdc++.h>




using namespace std;

const int DN=1e6+5;

int n,m,pr[DN],sol[DN],f,cnt,g,cost,viz[DN];

pair<int,pair<int,int> >mc[DN];

set<pair<int,int> >s;

long long sum;

vector<pair<int,int> >v[DN];



int main()

{

    FILE *fin=fopen("apm.in","r");

    FILE *fout=fopen("apm.out","w");



    fscanf(fin,"%d%d",&n,&m);

    for(int i=1;i<=m;i++)

    {

        fscanf(fin,"%d%d%d",&mc[i].second.first,&mc[i].second.second,&mc[i].first);

        f=mc[i].second.first;

        g=mc[i].second.second;

        cost=mc[i].first;

        v[f].push_back({g,cost});

        v[g].push_back({f,cost});

    }

    for(int i=0;i<n+1;i++)

    {

        pr[i]=-1;

        sol[i]=2e9;

        s.insert({sol[i],i});

    }

    if(m==0)

    {

        fprintf(fout,"%d",0);

        return 0;

    }

    s.erase(s.find({sol[1],1}));

    sol[1]=0;

    viz[1]=1;

        for(auto i:v[1])

            if(!viz[i.first])

            {

                if(sol[i.first]<=i.second)

                    continue;

                s.erase(s.find({sol[i.first],i.first}));

                sol[i.first]=i.second;

                s.insert({sol[i.first],i.first});

                pr[i.first]=1;

            }



    while(cnt<n-1)

    {



        cnt++;

        sum+=s.begin()->first;

        int nod=s.begin()->second;

        s.erase(s.begin());

        viz[nod]=1;

        for(auto i:v[nod])

            if(!viz[i.first])

            {

                if(sol[i.first]<=i.second)

                    continue;

                s.erase(s.find({sol[i.first],i.first}));

                sol[i.first]=i.second;

                s.insert({sol[i.first],i.first});

                pr[i.first]=nod;

            }

    }





    fprintf(fout,"%lld\n",sum);

    fprintf(fout,"%d\n",cnt);

    for(int i=0;i<=n;i++)

    {

        if(pr[i]==-1)

            continue;

        fprintf(fout,"%d %d\n",i,pr[i]);

    }



}
