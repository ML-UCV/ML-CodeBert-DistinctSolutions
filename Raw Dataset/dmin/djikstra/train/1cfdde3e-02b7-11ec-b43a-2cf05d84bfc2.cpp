#include <cstdio>
#include <vector>
#include <list>
#include <utility>
#include <cmath>
#include <queue>




using namespace std;



typedef pair<int,double> pereche;

vector < list < pereche > > Graf;

vector < double > d;

int vizitat[1501], drumuri[1501];

const int modulo = 104659;

const double epsilon = 1e-10;

struct order{

    bool operator()(const int &i,const int &j){

        return d[i] > d[j];

    }

};

priority_queue<int,vector<int>,order> Heap;

int n,m;



void citesc(){



    int x,y;

    double c;

    freopen("dmin.in","r",stdin);

    freopen("dmin.out","w",stdout);

    scanf("%d%d",&n,&m);

    Graf.resize(n+1);

    d.resize(n+1,1000000001);

    for(register int i=1;i<=m;++i){

        scanf("%d%d%lf",&x,&y,&c);

        c = log(c);

        Graf[x].push_back(pereche(y,c));

        Graf[y].push_back(pereche(x,c));

    }

}



void Dijkstra(){



    int top;

    vizitat[1] = 1;

    Heap.push(1);

    drumuri[1] = 1;

    d[1] = 0;

        while(!Heap.empty()){



            top = Heap.top();

            Heap.pop();

                for(list<pereche>::iterator it = Graf[top].begin();it!=Graf[top].end();++it)

                    if(d[it->first] > d[top] + it->second + epsilon){

                        drumuri[it->first] = drumuri[top];

                        d[it->first] = d[top] + it->second;



                        if(!vizitat[it->first]){

                            vizitat[it->first] = 1;

                            Heap.push(it->first);

                        }

                    }

                    else if(abs(d[it->first]- d[top] - it->second) <= epsilon){

                        drumuri[it->first] += drumuri[top];

                        drumuri[it->first] %= modulo;

                    }

        }

}



int main(){



    citesc();

    Dijkstra();

        for(register int i=2;i<=n;++i)

            printf("%d ",drumuri[i]);

return 0;

}
