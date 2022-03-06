#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
vector<pair <int,int> >a[30010];
int n,m,i,j,x,y,z,v[30010],c[900100],d[30010],s,u,p,start,cap2,cap1;
int main(){
    fin>>n>>m>>cap1>>cap2;
    for(i=1;i<=m;i++){
        fin>>x>>y>>z;
        a[x].push_back(pair<int,int>(y,z));
        a[y].push_back(pair<int,int>(x,z));
    }
   // for (i=1;i<=n;i++){
     //   sort( a[i].begin(), a[i].end() );
    //}

    c[1]=cap1;
    v[1]=1;
    u=1;
    p=1;
    while(p<=u){
        int nod=c[p];
        if(nod==cap2){
            break;
        }
        for(int ii=0;ii<a[nod].size();ii++){
            int vecin=a[nod][ii].first;
            if( v[vecin]==0){
                v[vecin]=1;
                if(nod<vecin){
                    d[vecin]=d[nod]+a[nod][ii].second;
                }
                else{
                    d[vecin]=d[nod]-a[nod][ii].second;
                }
                u++;
                c[u]=vecin;


            }
        }
        p++;
    }

    fout<<d[cap2];
}
