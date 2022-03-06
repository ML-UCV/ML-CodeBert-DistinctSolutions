#include <cstdio>
#include <fstream>
#include <vector>
#include <stack>
#include <bitset>


using namespace std;

ifstream f("party.in");

ofstream g("party.out");

int n,m,sol[205],ans;

vector <int> v[205],p[205];

stack <int> s;

bitset <205> b;





int cod(int x)

{

    if (x<0)

        return n-x;

    return x;



}

void dfs(int x)

{

    int i,y;

    b[x]=1;

    for (i=0;i<v[x].size();i++) {

        y=v[x][i];

        if (b[y]==0)

            dfs(y);

    }

    s.push(x);

}

int opus(int x)

{

    if (x<=n)

        return x+n;

    return x-n;

}

void dfst(int x)

{

    int i,y;

    b[x]=0;

    sol[opus(x)]=1;

    for (i=0;i<p[x].size();i++) {

        y=p[x][i];

        if (b[y]==1)

            dfst(y);

    }

}

void implic(int x,int y)

{

    x=cod(x);

    y=cod(y);

    v[x].push_back(y);

    p[y].push_back(x);



}

int main()

{

    int k,i,j;

    f>>n>>m;

    for (;m;m--) {

        f>>i>>j>>k;

        if (k==0) {

            implic(-i,j);

            implic(-j,i);

        }

        else

            if (k==1) {

                implic(-i,-j);

                implic(j,i);

            }

        else

            if (k==2) {

                implic(-j,-i);

                implic(i,j);

            }

        else {

            implic(i,-j);

            implic(j,-i);

        }

    }

    for (i=1;i<=2*n;i++)

        if (b[i]==0)

            dfs(i);

    while (!s.empty()) {

        i=s.top();

        s.pop();

        if (b[i]==1&&b[opus(i)]==1)

            dfst(i);

    }

    for (i=1;i<=n;i++)

        ans+=sol[i];

    g<<ans<<'\n';

    for (i=1;i<=n;i++)

        if (sol[i])

            g<<i<<'\n';

    return 0;

}
