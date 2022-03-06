#include <bits/stdc++.h>
using namespace std;



const int NMAX = 100005;

int cnt;

vector<int> edges[NMAX],reverse_edges[NMAX] , ctc[NMAX];

int viz[NMAX];

stack<int> st;

void dfs(int nod)

{

    viz[nod] = 1 ;

    for(auto point : edges[nod])

        if(!viz[point])

            dfs(point);

    st.push(nod);

}

void dfs1(int nod)

{

    ctc[cnt].push_back(nod);

    viz[nod] = 1;

    for(auto point : reverse_edges[nod])

        if(!viz[point])

            dfs1(point);

}

int main()

{

    freopen("ctc.in","r",stdin);

    freopen("ctc.out","w",stdout);

    int n , m , i , j , a , b ;

    cin >> n >> m;

    for( i = 0 ; i < m ; ++i)

    {

        scanf("%d%d",&a,&b);

        edges[a].push_back(b);

        reverse_edges[b].push_back(a);

    }

    for(i = 1 ; i <= n; ++i)

        if(!viz[i])dfs(i);

    memset(viz,0,sizeof(viz));

    while(!st.empty())

    {

        if(!viz[st.top()])

            {dfs1(st.top()); ++ cnt;}

        st.pop();

    }

    cout<<cnt<<'\n';

    for( i = 0 ; i<cnt;++i)

    {for(auto point : ctc[i])

        printf("%d ",point);

        printf("\n");

    }

    return 0;

}
