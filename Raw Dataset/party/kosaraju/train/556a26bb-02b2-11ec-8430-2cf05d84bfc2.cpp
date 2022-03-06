#include<fstream>
#include<vector>
using namespace std;

ifstream fi("party.in");

ofstream fo("party.out");

vector<int> A[205],AT[205];

int n,m,i,x,y,z,rez,R[205],Viz[205],top,S[205];



void dfs(int nod)

{

    vector<int>::iterator it;

    Viz[nod]=1;

    for(it=A[nod].begin(); it!=A[nod].end(); it++)

        if(!Viz[*it])

            dfs(*it);

    S[++top]=nod;

}



void dfs(int nod, int val)

{

    R[nod]=val;

    vector<int>::iterator it;

    for(it=AT[nod].begin(); it!=AT[nod].end(); it++)

        if(R[*it]==-1)

            dfs(*it,val);

}



int main()

{

    fi>>n>>m;

    for(i=1; i<=m; i++)

    {

        fi>>x>>y>>z;

        x=2*x;

        y=2*y;

        if(z==1 || z==3)

            y^=1;

        if(z==2 || z==3)

            x^=1;

        A[x^1].push_back(y);

        A[y^1].push_back(x);

        AT[x].push_back(y^1);

        AT[y].push_back(x^1);

    }

    for(i=2; i<=2*n+1; i++)

        if(!Viz[i])

            dfs(i);

    for(i=2; i<=2*n+1; i++)

        R[i]=-1;

    for(i=2*n; i>=1; i--)

        if(R[S[i]]==-1 && R[S[i]^1]==-1)

            dfs(S[i],0);

    for(i=2; i<=2*n; i+=2)

        if(R[i]==-1)

        {

            R[i]=1;

            rez++;

        }

    fo<<rez<<"\n";

    for(i=1; i<=n; i++)

        if(R[2*i]==1)

            fo<<i<<"\n";

    fi.close();

    fo.close();

    return 0;

}
