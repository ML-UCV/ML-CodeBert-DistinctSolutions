#include <bits/stdc++.h>






using namespace std;

ifstream fi("dmin.in");
ofstream fo("dmin.out");

struct HeapNode{
    int nod;
    double val;
    bool operator< (const HeapNode &other) const{
        return val>other.val;
    }
};

int n,m,x,y;
double c;
vector<pair<int,double>> G[1500 +5];
priority_queue<HeapNode> pq;
double dist[1500 +5];
int nrdrm[1500 +5];
int viz[1500 +5];

void dijkstra(){
    for(int i=2;i<=n;i++){
        dist[i]=(1LL<<31)-1;
    }
    dist[1]=0;
    HeapNode x;
    int nod,nod2;
    double val,val2;
    pq.push({1,0});
    while(!pq.empty()){
        x=pq.top();
        pq.pop();
        nod=x.nod;
        val=x.val;
        if(dist[nod]<val){
            continue;
        }
        for(int i=0;i<G[nod].size();i++){
            nod2=G[nod][i].first;
            val2=G[nod][i].second;
            if(dist[nod2]>dist[nod]+val2){
                dist[nod2]=dist[nod]+val2;
                pq.push({nod2,dist[nod2]});
            }
        }
    }
}

void calc_nrdrm(){
    for(int i=2;i<=n;i++){
        nrdrm[i]=0;
    }
    nrdrm[1]=1;
    pq.push({1,0});
    viz[1]=1;
    HeapNode x;
    int nod,nod2;
    double val,val2;
    while(!pq.empty()){
        x=pq.top();
        pq.pop();
        nod=x.nod;
        val=x.val;
        for(int i=0;i<G[nod].size();i++){
            nod2=G[nod][i].first;
            val2=G[nod][i].second;
            if(abs(dist[nod2]-dist[nod]-val2)<=0.0000001){
                nrdrm[nod2]+=nrdrm[nod];
                nrdrm[nod2]%=104659;
                if(!viz[nod2]){
                    viz[nod2]=1;
                    pq.push({nod2,dist[nod2]});
                }
            }
        }
    }
}

int main(){
    fi>>n>>m;
    for(int i=1;i<=m;i++){
        fi>>x>>y>>c;
        c=log(c);
        G[x].push_back(make_pair(y,c));
        G[y].push_back(make_pair(x,c));
    }
    dijkstra();
    calc_nrdrm();
    for(int i=2;i<=n;i++){
        fo<<nrdrm[i]<<' ';
    }
    fi.close();
    fo.close();
}
