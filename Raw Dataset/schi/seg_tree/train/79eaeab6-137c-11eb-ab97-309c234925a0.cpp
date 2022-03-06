#include <iostream>
#include <cstdio>



using namespace std;

int n, v[30005], l[2*30005];
pair<int,int> arbint[4*30005];

pair<int,int> maxPair(pair<int,int> a, pair<int,int> b){
    if(a.first<b.first)
        return a;
    if(b.first<a.first)
        return b;
    if(a.second>b.second)
        return a;
    return b;
}

void construieste(int st = 1, int dr = n, int pos = 1){
    if(st==dr){
        arbint[pos] = {v[st],st};
        return ;
    }

    int mij = (st+dr)/2;

    construieste(st,mij,2*pos);
    construieste(mij+1,dr,2*pos+1);

    arbint[pos] = maxPair(arbint[2*pos], arbint[2*pos+1]);
}

void actualizareNod(int k, int st = 1, int dr = n, int pos = 1){
    if(l[pos]){
        if(st!=dr){
            arbint[2*pos].first += l[pos];
            arbint[2*pos+1].first += l[pos];
            l[2*pos] += l[pos];
            l[2*pos+1] += l[pos];
        }
        l[pos] = 0;
    }

    if(st==dr){
        arbint[pos].first = 30005;
        return ;
    }

    int mij = (st+dr)/2;
    if(k<=mij)
        actualizareNod(k,st,mij,2*pos);
    else
        actualizareNod(k,mij+1,dr,2*pos+1);

    arbint[pos] = maxPair(arbint[2*pos], arbint[2*pos+1]);
}

void actualizareInterval(int qst, int qdr, int st = 1, int dr = n, int pos = 1){
    if(l[pos]){
        if(st!=dr){
            arbint[2*pos].first += l[pos];
            arbint[2*pos+1].first += l[pos];
            l[2*pos] += l[pos];
            l[2*pos+1] += l[pos];
        }
        l[pos] = 0;
    }
    if(qst<=st && dr<=qdr){
        arbint[pos].first++;
        l[pos]++;
        return ;
    }

    int mij = (st+dr)/2;
    if(qdr<=mij)
        actualizareInterval(qst,qdr,st,mij,2*pos);
    else if(mij<qst)
        actualizareInterval(qst,qdr,mij+1,dr,2*pos+1);
    else{
        actualizareInterval(qst,qdr,st,mij,2*pos);
        actualizareInterval(qst,qdr,mij+1,dr,2*pos+1);
    }

    arbint[pos] = maxPair(arbint[2*pos], arbint[2*pos+1]);
}

int main()
{
    freopen("schi.in","r",stdin);
    freopen("schi.out","w",stdout);

    scanf("%d", &n);
    for(int i=1;i<=n;++i)
        scanf("%d", &v[i]);

    construieste();

    for(int i=1;i<n;++i){
        int k = arbint[1].second;
        cout<<k<<"\n";
        actualizareNod(k);
        if(k!=1)
            actualizareInterval(1,k-1);
    }
    cout<<arbint[1].second;
    return 0;
}
