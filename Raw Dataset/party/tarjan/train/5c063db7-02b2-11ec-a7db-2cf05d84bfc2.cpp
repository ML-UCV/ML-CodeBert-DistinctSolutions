#include <fstream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

ifstream f("party.in");

ofstream af("party.out");

int low[210],niv[210],w[210];

int n,m,sol,t,x,y,g,i,j;

set <int> r;

stack <int> s;

vector <int> l[210];

void dfs (int nod)

{

   niv[nod]=low[nod]=++g;

   s.push(nod);

   for(int i=0;i<l[nod].size();i++) {

       if (niv[l[nod][i]]==0)

            dfs(l[nod][i]);

        if (niv[l[nod][i]]>0)

            low[nod]=min(low[nod],low[l[nod][i]]);

   }

   if (low[nod]==niv[nod]) {

       r.clear();

       do {

            x=s.top();

            s.pop();

            r.insert(x);



            if (w[x]==0){

                w[x]=1;

                if (x<=n)

                    w[x+n]=-1;

                else

                    w[x-n]=-1;

            }

            niv[x]*=-1;

       }while (x!=nod);

   }

}

int main ()

{

    f>>n>>m;

    for (i=1;i<=m;i++) {

        f>>x>>y>>t;

        if (t==1){

            y*=-1;

        }else{

            if (t==2)

                x*=-1;

            else

                if (t==3){

                    x*=-1;

                    y*=-1;

                }

        }



        if (x>0){

            if (y>0) {

                l[x+n].push_back(y);

                l[y+n].push_back(x);

            }else {

                l[x+n].push_back(-y+n);

                l[-y].push_back(x);

            }

        }else{

            if (y>0) {

                l[-x].push_back(y);

                l[y+n].push_back(-x+n);

            }else{

                l[-x].push_back(-y+n);

                l[-y].push_back(-x+n);

            }

        }

    }

    for (i=1;i<=2*n;i++)

        if (niv[i]==0)

            dfs(i);

    for (i=1; i<=n; i++)

        if (w[i]==1)

            sol++;

    af<<sol<<"\n";

    for (i=1;i<=n;i++)

        if (w[i]==1)

            af<<i<<"\n";

    f.close(); af.close();

    return 0;

}
