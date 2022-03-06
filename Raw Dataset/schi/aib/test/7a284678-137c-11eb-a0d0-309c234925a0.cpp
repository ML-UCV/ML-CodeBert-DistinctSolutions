#include <iostream>
#include <cstdio>


using namespace std;

int N, List[30001], i, j, Sol[30001];

class BIT{

    int V[30001];

    int Get(int target){

        int out=0;

        for(j=target; j>=1; j-=j&(-j)) out+=V[j];

        return out;

    }

    int BS(int val, int S, int D){

        int mid=(S+D)/2;

        int x=Get(mid);

        if(x==val && Sol[mid]==0) return mid;

        if(x<val) return BS(val, mid+1, D);

        else return BS(val, S, mid);

    }

public:

    void Add(int val, int target){

        for(j=target; j<=N; j+=j&(-j)) V[j]+=val;

        return;

    }

    int Find(int val){

        return BS(val, 1, N);

    }

};

BIT Arb;

int main()

{

    freopen("schi.in", "r", stdin);

    freopen("schi.out", "w", stdout);

    scanf("%d", &N);

    for(i=1; i<=N; ++i) {scanf("%d", &List[i]); Arb.Add(1, i);}

    for(i=N; i>=1; --i){

        int x=Arb.Find(List[i]);

        Sol[x]=i;

        Arb.Add(-1, x);

    }

    for(i=1; i<=N; ++i) printf("%d\n", Sol[i]);

    return 0;

}
