#include <fstream>
#include <list>
#include <set>
#include <stack>
#include <bitset>


using namespace std;

ifstream f("party.in");

ofstream g("party.out");

int n,m,gr,nr,pas;



int low[111*2],niv[111*2],V[2*111];



list<int> L[2*111];

stack<int> S;

bitset<111*2> viz,IS;



int val(int x){

    return (x%2==0?-1:1);

}



void dfs(int nod){

    int x,q;

    list<int>::iterator it;

    low[nod]=niv[nod]=++gr;

    S.push(nod);

    viz[nod]=IS[nod]=1;



    for(it=L[nod].begin();it!=L[nod].end();it++){

        if(!viz[*it]){

            dfs(*it);

            low[nod]=min(low[nod],low[*it]);

        }

        else if(IS[*it])

            low[nod]=min(low[nod],low[*it]);

    }



    if(low[nod]==niv[nod]){

        do{ x=S.top(),S.pop();

            IS[x]=0;

            if(!V[x])

                V[x]=1,(x<=n?V[x+n]=-1,nr++:V[x-n]=-1);

        }while(x!=nod);

    }

}



int main(void){

    register int i,j,x,y,z;



    f>>n>>m;

    for(i=1;i<=m;i++){

        f>>x>>y>>z;

        switch(z){

            case 0:

                L[x+n].push_back(y);

                L[y+n].push_back(x);

                break;

            case 1:

                L[x+n].push_back(y+n);

                L[y].push_back(x);

                break;

            case 2:

                L[x].push_back(y);

                L[y+n].push_back(x+n);

                break;

            default:

                L[x].push_back(y+n);

                L[y].push_back(x+n);

        }

    }



    for(i=1;i<=2*n;i++) if(!viz[i]) dfs(i);



    g<<nr<<"\n";

    for(i=1;i<=n;i++)

        if(V[i]>0) g<<i<<"\n";

    f.close();

    g.close();

    return 0;

}
