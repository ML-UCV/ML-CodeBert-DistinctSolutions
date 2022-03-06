#include <fstream>
#include<vector>
#define pp pair<int,int>
#define inf 9999999
#include<stdlib.h>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
vector<pp> a[30001];
int n,m,x,y,d[100001];
bool v[30001];
void cit(){
    int i,j,w,h;
    fin>>n>>m>>x>>y;
    for(h=1;h<=m;h++){
        fin>>i>>j>>w;
        a[i].push_back(pp(j,w));
        a[j].push_back(pp(i,-w));
    }
    fin.close();
}

void dfs(int x){
    v[x]=true;
    for(vector<pp>::iterator it=a[x].begin();it!=a[x].end();it++)
        if(v[it->first]==false){
            d[it->first]=d[x]+it->second;
            dfs(it->first);
            if(it->first==y){
                fout<<d[y];
                exit(0);
            }
        }
}
int main(){
    cit();
    dfs(x);
    fout<<d[y];
    fout.close();
    return 0;
}
