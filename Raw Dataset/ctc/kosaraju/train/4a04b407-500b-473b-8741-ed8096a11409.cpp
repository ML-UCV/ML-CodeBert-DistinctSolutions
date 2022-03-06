#include <bits/stdc++.h>


using namespace std;

ifstream f ("ctc.in") ;

ofstream g ("ctc.out") ;

int N , M , x , y , cnt = 0;

stack <int> st;

bool viz[100010] ;

vector <int> G[100010] , GT[100010] , CTC[100010];

void DFS (int nod)

{

    viz[nod] = true ;

    int lg = G[nod].size() ;

    for (int i = 0 ; i < lg; ++i)

    {

        int vec = G[nod][i] ;

        if (!viz[vec]) DFS(vec);

    }



    st.push(nod) ;

}

void DFST(int nod)

{

    viz[nod] = false;

    int lg = GT[nod].size() ;

    for (int i = 0 ; i < lg ; ++i)

    {

        int vec = GT[nod][i];

        if (viz[vec])DFST(vec) ;

    }



    CTC[cnt].push_back(nod) ;

}

int main()

{

    f >> N >> M ;

    for (int i = 1 ; i <= M ; ++i)

    {

        f >> x >> y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }



    for (int nod = 1; nod <= N ; ++nod)

        if (!viz[nod]) DFS(nod) ;



    while (!st.empty())

    {

        int nod = st.top();

        st.pop() ;

        if (viz[nod]) {cnt ++ ; DFST(nod) ;}

    }



    g << cnt << '\n' ;

    for (int i = 1 ; i <= cnt ; ++i)

    {

        int lg = CTC[i].size();

        for (int j = 0 ; j < lg ; ++j) g << CTC[i][j] << ' ' ;

        g << '\n' ;

    }

    f.close();

    g.close();

    return 0 ;

}
