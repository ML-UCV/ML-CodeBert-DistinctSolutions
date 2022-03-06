# include <fstream>
# include <cmath>
# include <vector>
# include <queue>
using namespace std;

ifstream fin("dmin.in");

ofstream fout("dmin.out");

struct nod{

    int vecin;

    double cost;

};

vector<nod> Lista[1510];

queue<int> q;

nod a;

bool Marcat[1510];

int var[1510],sol[1510],n,m,i,x,y,c;

double d[1510];

bool egal(double a,double b){

    if(a-b<=1e-7&&a-b>=-1e-7)

        return 1;

    return 0;

}

void bmfrd(){

    Marcat[1]=1;

    var[1]=1;

    q.push(1);

    d[1]=1;

    while(!q.empty()){

        int nc=q.front();

        q.pop();

        for(int i=0;i<Lista[nc].size();i++){

            int nv=Lista[nc][i].vecin;

            double cost=Lista[nc][i].cost;

            if(d[nc]+cost<d[nv]&&(!egal(d[nc]+cost,d[nv]))){

                d[nv]=d[nc]+cost;

                var[nv]=var[nc];

                if(!Marcat[nv]){

                    Marcat[nv]=1;

                    q.push(nv);

                }

            }

            else if(egal(d[nc]+cost,d[nv])){

                var[nv]+=var[nc];

                var[nv]%=104659;

                if(!Marcat[nv]){

                    Marcat[nv]=1;

                    q.push(nv);

                }

            }

        }

        sol[nc]+=var[nc];

        sol[nc]%=104659;

        var[nc]=0;

        Marcat[nc]=0;

    }

}

int main () {

    fin>>n>>m;

    for(i=2;i<=n;i++)

        d[i]=1000000000;

    for(i=1;i<=m;i++){

        fin>>x>>y>>c;

        a.vecin=y;

        a.cost=log(c);

        Lista[x].push_back(a);

        a.vecin=x;

        Lista[y].push_back(a);

    }

    bmfrd();

    for(i=2;i<=n;i++)

        fout<<sol[i]<<" ";

    fout<<"\n";

    return 0;

}
