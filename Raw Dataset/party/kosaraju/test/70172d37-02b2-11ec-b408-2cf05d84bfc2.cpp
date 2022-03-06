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

inline int nott(int val) {
    if(val>n) {
        return val-n;
    }
    return val+n;
}

void dfs1(int nod) {
    viz[nod]=true;
    for(vector<int>::iterator it=G[nod].begin(); it!=G[nod].end(); it++) {
        if(!viz[*it]) {
            dfs1(*it);
        }
    }
    st[++st[0]]=nod;
}

void dfs2(int nod) {
    viz[nod]=true;

    val[nott(nod)]=true;

    for(vector<int>::iterator it=G2[nod].begin(); it!=G2[nod].end(); it++) {
        if(!viz[*it]) {
            dfs2(*it);
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
            b=nott(b);
        }
        else if(t==2) {
            a=nott(a);
        }
        else if(t==3) {
            a=nott(a);
            b=nott(b);
        }


        G[nott(a)].push_back(b);
        G[nott(b)].push_back(a);

        G2[b].push_back(nott(a));
        G2[a].push_back(nott(b));
    }

    for(int i=1;i<=2*n;i++) {
        if(!viz[i]) {
            dfs1(i);
        }
    }
    memset(viz,0,sizeof(viz));
    for(int i=2*n;i>=1;i--) {
        if(!viz[st[i]]&&!viz[nott(st[i])]) {
            dfs2(st[i]);
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
