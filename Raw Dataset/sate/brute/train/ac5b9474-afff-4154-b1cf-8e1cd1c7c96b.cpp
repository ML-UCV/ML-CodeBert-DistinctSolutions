#include <fstream>
#include <vector>
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

int n,m,x,y,cnt,k,i,j,p,u,c[30001],f[30001],drum[30001];

vector < pair<int,int> > l[30001];

int main(){
    fin>>n>>m>>x>>y;
    for(cnt=1;cnt<=m;cnt++){
        fin>>i>>j>>k;
        l[i].push_back(make_pair(j,k));
        l[j].push_back(make_pair(i,0-k));
    }

    c[1]=x;
    f[x]=1;
    p=1; u=1;

    while(f[y]==0 && p<=u){
        for(k=0;k<l[c[p]].size();k++){
            if(f[l[c[p]][k].first]==0){
                c[++u]=l[c[p]][k].first;
                drum[l[c[p]][k].first]=drum[c[p]]+l[c[p]][k].second;
                f[l[c[p]][k].first]=1;
            }
        }
        p++;
    }

    fout<<drum[y];

    return 0;
}
