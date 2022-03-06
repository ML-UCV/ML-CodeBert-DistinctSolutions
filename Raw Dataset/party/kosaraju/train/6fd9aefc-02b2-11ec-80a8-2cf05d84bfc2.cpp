#include <stdio.h>
#include <vector>




using namespace std;

vector<int>oo[2*100 +1],OO[2*100 +1];

vector<int>*o=oo+100,*O=OO+100;

bool C[2*100 +1],V[2*100 +1];

bool*c=C+100,*v=V+100;

int L[2*100],l,S;

void dfs1(int i){

    c[i]=true;

    int s=o[i].size();

    for(int j=0;j<s;++j) if(!c[o[i][j]]) dfs1(o[i][j]);

    L[--l]=i;

    }

void dfs2(int i){

    c[i]=false;

    v[-i]=true;

    if(i<0) ++S;

    int s=O[i].size();

    for(int j=0;j<s;++j) if(c[O[i][j]]) dfs2(O[i][j]);

    }

int main(){

    freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);

    int n,m,x,y,z;

    scanf("%i%i",&n,&m);

    for(int i=0;i<m;++i){

        scanf("%i%i%i",&x,&y,&z);

        if(z&1) y=-y;

        if(z&2) x=-x;

        o[-x].push_back(y);

        o[-y].push_back(x);

        O[y].push_back(-x);

        O[x].push_back(-y);

        }

    l=n<<1;

    for(int i=-n;i<n+1;++i){

        if(!i)continue;

        if(!c[i])dfs1(i);

        }

    for(int i=0;i<n<<1;++i){

        if(v[-L[i]]||v[L[i]])continue;

        if(c[L[i]])dfs2(L[i]);

        }

    printf("%i\n",S);

    for(int i=1;i<n+1;++i) if(v[i])printf("%i ",i);

    return 0;

    }
