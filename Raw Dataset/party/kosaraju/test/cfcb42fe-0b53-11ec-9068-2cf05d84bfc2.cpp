#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N=110;

vector<int> G[2*MAX_N];
vector<int> G2[2*MAX_N];

bool viz[2*MAX_N];
bool val[2*MAX_N];
int st[2*MAX_N];

int n;

inline int negare(int val) {
    if(val>n) {
        return val-n;
    }
    return val+n;
}

void dfffs(int gr_nod) {
    viz[gr_nod]=true;
    for(vector<int>::iterator it=G[gr_nod].begin(); it!=G[gr_nod].end(); it++) {
        if(!viz[*it]) {
            dfffs(*it);
        }
    }
    st[++st[0]]=gr_nod;
}

void dfstrv(int gr_nod) {
    viz[gr_nod]=true;

    val[negare(gr_nod)]=true;

    for(vector<int>::iterator it=G2[gr_nod].begin(); it!=G2[gr_nod].end(); it++) {
        if(!viz[*it]) {
            dfstrv(*it);
        }
    }
}

int main() {
    freopen("party.in","r",stdin);
    freopen("party.out","w",stdout);

    int m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        int t,a,b;
        scanf("%d%d%d",&a,&b,&t);
        if(t==0) {

        }
        else if(t==1) {
            b=negare(b);
        }
        else if(t==2) {
            a=negare(a);
        }
        else if(t==3) {
            a=negare(a);
            b=negare(b);
        }


        G[negare(a)].push_back(b);
        G[negare(b)].push_back(a);

        G2[b].push_back(negare(a));
        G2[a].push_back(negare(b));
    }

    for(int i=1;i<=2*n;i++) {
        if(!viz[i]) {
            dfffs(i);
        }
    }
    memset(viz,0,sizeof(viz));
    for(int i=2*n;i>=1;i--) {
        if(!viz[st[i]]&&!viz[negare(st[i])]) {
            dfstrv(st[i]);
        }
    }

    vector<int> sol;
    for(int i=1;i<=n;i++) {
        if(val[i]) {
            sol.push_back(i);
        }
    }

    printf("%d\n",sol.size());
    for(vector<int>::iterator it=sol.begin(); it!=sol.end(); it++) {
        printf("%d\n",*it);
    }

    return 0;
}
