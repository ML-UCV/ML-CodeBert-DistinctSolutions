    #include<cstdio>
    #include<vector>
    #include<cstring>
    using namespace std;





    int N , M , p[201] , sol[201] , nr , k , poz[201] , rez;

    vector<int> G[201] , Gt[201] , CC[201];

    bool u[201];



    void read();

    void solve();

    void write();

    int abs(int x)

    {

        if(x < 0)return -x+N;

        return x;

    }

    int neg(int x)

    {

        if(x > N)return x-N;

        return x+N;

    }

    void dfs1(int nod);

    void dfs2(int nod);



    int main()

    {

        read();

        solve();

        write();

        return 0;

    }



    void read()

    {

        int x , y , t;

        freopen("party.in" , "r" , stdin );

        scanf("%d%d" , &N , &M );

        for(int i = 1 ; i<= M ; ++i )

        {

            scanf("%d%d%d" , &x , &y , &t);

            if(t == 1)y = neg(y);

            if(t == 2)x = neg(x);

            if(t == 3)x = neg(x),y = neg(y);

            G[neg(x)].push_back(y);

            G[neg(y)].push_back(x);

            Gt[y].push_back(neg(x));

            Gt[x].push_back(neg(y));

        }

    }



    void solve()

    {

        for(int i = 1 ; i <= 2*N ; ++i )

            if(!u[i])dfs1(i);

        memset(u,0,sizeof(u));

        for(int i = 2*N ; i ; i-- )

            if(!u[p[i]])nr++,dfs2(p[i]);

        memset(sol,0-1,sizeof(sol));

        for(int i = 1 ; i<= nr ; ++i )

        {

            if(sol[CC[i][0]] != -1)continue;

            for(int j = 0 ; j <(int)CC[i].size() ; ++j )

            {

                sol[CC[i][j]] = 0;

                sol[neg(CC[i][j])] = 1;

            }

        }

    }



    void dfs1(int nod)

    {

        u[nod] = 1;

        for(int j = 0 ; j <(int)G[nod].size() ; ++j )

        if(!u[G[nod][j]])dfs1(G[nod][j]);

        p[++k] = nod;

    }



    void dfs2(int nod)

    {

        u[nod] = 1;

        CC[nr].push_back(nod);

        poz[nod] = nr;

        for(int j = 0 ; j < (int)Gt[nod].size() ; ++j )

            if(!u[Gt[nod][j]])dfs2(Gt[nod][j]);

    }



    void write()

    {

        freopen("party.out" , "w" , stdout );

        for(int i = 1 ; i<= N ; ++i )

            rez+=sol[i];

        printf("%d\n" , rez);

        for(int i = 1 ; i<= N ; ++i )

            if(sol[i])printf("%d\n" , i);

    }
