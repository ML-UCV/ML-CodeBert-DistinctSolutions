#include <bits/stdc++.h>
using namespace std;

struct graf{

    int x,y,cost;

};



vector<int>gr(200003,0);

vector<graf>v(200003);

vector<int>ind(200003);

bool cmp(int i,int j){

    return (v[i].cost<v[j].cost);

}



int grupa(int x){

    if(gr[x]==x)

        return x;

    gr[x]=grupa(gr[x]);

    return gr[x];

}



void reuniune(int i,int j){

 gr[grupa(i)] = grupa(j);

}



int main()

{

    freopen("apm.in","r",stdin);

    freopen("apm.out","w",stdout);



    int n,m;

    scanf("%d%d",&n,&m);





    for(int i=1;i<=m;i++){

        int x,y,c;

        scanf("%d%d%d",&v[i].x,&v[i].y,&v[i].cost);

        ind[i]=i;

    }



    sort(ind.begin()+1,ind.begin()+m+1,cmp);
    for(int i=1;i<=n;i++)

        gr[i]=i;

    int s=0;

    vector<int>sol;

    for(int i=1;i<=m;i++){

        if(grupa(v[ind[i]].x)!=grupa(v[ind[i]].y)){

            s=s+v[ind[i]].cost;

            reuniune(v[ind[i]].x,v[ind[i]].y);

            sol.push_back(ind[i]);

        }



    }



    printf("%d\n%d\n",s,n-1);

    for(auto i:sol)

        printf("%d %d\n",v[i].x,v[i].y);





    return 0;

}
