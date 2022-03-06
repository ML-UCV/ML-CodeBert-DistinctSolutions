#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;
ifstream in("sate.in");
ofstream out("sate.out");
vector < pair <int , int > > a[30005];
bitset<30005> viz;
queue < int > q;
int d[30005];
vector < pair < int , int> >::iterator it;
int n,m,s1,s2,y,x,c,nod,i;
int main()
{
    in>>n>>m>>s1>>s2;
    for(i=1;i<=m;++i){
        in>>x>>y>>c;
        a[x].push_back(make_pair(y,c));
        a[y].push_back(make_pair(x,c));
    }
    viz[s1]=true;
    d[s1]=0;
    q.push(s1);
    while(!q.empty()){
        nod=q.front();
        q.pop();
        for(it=a[nod].begin();it!=a[nod].end();++it){
            int vecin=it->first;
            int cost =it->second;
            if(viz[vecin]==0){
                if(vecin<nod){
                    d[vecin]=d[nod]-cost;
                }
                else if(vecin>nod){
                    d[vecin]=d[nod]+cost;
                }
                q.push(vecin);
                viz[vecin]=true;
                if(vecin==s2) {
                    out<<d[s2];
                    return 0;
                }
            }
        }
        }
    return 0;
}
