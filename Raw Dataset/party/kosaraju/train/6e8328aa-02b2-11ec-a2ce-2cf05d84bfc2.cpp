#include <fstream>
#include <cstring>
#include <vector>
using namespace std;



ifstream F("party.in");

ofstream G("party.out");







const int N = 110;

vector<int> v[N<<1],w[N<<1],stack;

bool mark[N<<1],ans[N<<1],no_sol;

int n,m;



int neg(int x)

{

    return x > n ? x - n : x + n;

}



void dff(int x)

{

    mark[x] = 1;

    for (vector<int>::iterator y=v[x].begin();y!=v[x].end();++y)

        if ( !mark[*y] )

            dff(*y);

    stack.push_back( x );

}



void dfs(int x)

{

    if ( ans[x] ) no_sol = 1;

    mark[x] = 1;

    ans[neg(x)] = 1;

    for (vector<int>::iterator y=w[x].begin();y!=w[x].end();++y)

        if ( !mark[*y] )

            dfs(*y);

}



int main()

{

    F>>n>>m;

    for (int i=1,t,x,y;i<=m;++i)

    {

        F>>x>>y>>t;

        if ( t == 3 )

        {

            x = neg(x);

            y = neg(y);

        } else

        if ( t == 1 )

        {

            y = neg(y);

        } else

        if ( t == 2 )

        {

            x = neg(x);

        }

        v[neg(x)].push_back(y);

        v[neg(y)].push_back(x);

        w[y].push_back(neg(x));

        w[x].push_back(neg(y));

    }

    for (int i=1;i<=2*n;++i)

        if ( !mark[i] )

            dff(i);

    memset(mark,0,sizeof(mark));

    for (;!stack.empty();stack.pop_back())

    {

        int x = stack.back();

        if ( !mark[x] && !mark[neg(x)] )

            dfs(x);

    }

    if ( no_sol )

        G<<"-1\n";

    else

    {

        int co = 0;

        for (int i=1;i<=n;++i)

            if ( ans[i] )

                ++co;

        G<<co<<'\n';

        for (int i=1;i<=n;++i)

            if ( ans[i] )

                G<<i<<'\n';

    }

}
