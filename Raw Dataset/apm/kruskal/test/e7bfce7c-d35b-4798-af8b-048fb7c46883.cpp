#include <bits/stdc++.h>


using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");

const int NMAX=200003;

int n,m,father[NMAX],s[NMAX],costmin;

int Find(int node){

    if(father[node]==node)

        return node;

    return father[node]=Find(father[node]);

}

void Union(int a,int b){

    int fa=Find(a),fb=Find(b);

    if(fa==fb)

        return;

    if(s[fa]<s[fb])

        swap(fa,fb);

    father[fb]=fa;

    s[fa]+=s[fb];

}

struct edge{

    int a,b,cost;

    bool operator <(const edge&aux)const{

        return aux.cost>cost;

    }

};

vector<edge>v,rasp;

int main()

{

    in>>n>>m;

    for(int i=1;i<=n;i++)

        father[i]=i,s[i]=1;

    for(int i=1,a,b,cost;i<=m;i++){

        in>>a>>b>>cost;

        v.push_back({a,b,cost});

    }

    sort(v.begin(),v.end());

    for(auto y:v){

        int a=y.a,b=y.b,cost=y.cost;

        int fa=Find(a),fb=Find(b);

        if(fa==fb)

           continue;

        Union(a,b);

        rasp.push_back({a,b});

        costmin+=cost;

    }

    out<<costmin<<'\n'<<n-1<<'\n';

    for(auto y:rasp)

        out<<y.a<<" "<<y.b<<'\n';

    return 0;

}
