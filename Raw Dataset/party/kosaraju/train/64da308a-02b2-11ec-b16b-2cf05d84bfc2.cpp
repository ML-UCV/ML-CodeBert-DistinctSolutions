#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;



long n,m,i,nn,x,y,op,cnt;
vector<long> gIn[2011],gOut[2011];
vector<long> Comp[2011],tmp;
bool vis[2011];
long ctc[2011],col[2011];

stack<long> S;

inline void addImp(long a,long b){
    a+=nn; b+=nn;
    gIn[a].push_back(b);
    gOut[b].push_back(a);
}

inline void aORb(long a,long b){
    addImp(-a,b);
    addImp(-b,a);
}

void dfsF(long node){
    vis[node] = true;
    for(long i=0;i<gIn[node].size();i++){
        long newNode = gIn[node][i];
        if(!vis[newNode]) dfsF(newNode);
    }
    S.push(node);
}

void dfsB(long node){
    ctc[node] = cnt; tmp.push_back(node);
    for(long i=0;i<gOut[node].size();i++){
        long newNode = gOut[node][i];
        if(!ctc[newNode]) dfsB(newNode);
    }
}

long getMust(long act){
    for(long i=0;i<Comp[act].size();i++){
        long newNode = Comp[act][i];
        if(col[newNode]) return col[newNode];
    }
    return 0;
}

void setCol(long act,long mCol){
    long inv;
    if(mCol == 1) inv = 2; else inv = 1;
    for(long i=0;i<Comp[act].size();i++){
        long newNode = Comp[act][i];

        col[newNode] = mCol;
        col[-(newNode-nn)+nn] = inv;

        if(mCol == 2)
        for(long j=0;j<gIn[newNode].size();j++){
            long node = gIn[newNode][j];
            col[node] = 2;
        }
    }
}

int main()
{
    freopen("party.in","r",stdin);
    freopen("party.out","w",stdout);

    scanf("%ld %ld",&n,&m); nn=n; n<<=1;
    for(i=1;i<=m;i++){
        scanf("%ld %ld %ld",&x,&y,&op);
        switch(op){
            case 0 : aORb(x,y); break;
            case 1 : aORb(x,-y); break;
            case 2 : aORb(-x,y); break;
            case 3 : aORb(-x,-y); break;
        }
    }

    for(i=0;i<=n;i++){
        if(!vis[i]) dfsF(i);
    }

    while(!S.empty()){
        long node = S.top(); S.pop();
        if(!ctc[node]){
            cnt++;
            tmp.clear();
            dfsB(node);
            Comp[cnt] = tmp;
        }
    }

    for(i=1;i<=cnt;i++){
        long must = getMust(i);
        if(must == 0) must = 1;
        setCol(i,must);
    }

    cnt = 0;
    for(i=nn+1;i<=n;i++) {
        if(col[i]==2) cnt++;
    }
    printf("%ld\n",cnt);
    for(i=nn+1;i<=n;i++) {
        if(col[i]==2) printf("%ld\n",i-nn);
    }

    return 0;
}
