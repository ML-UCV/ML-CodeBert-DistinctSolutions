#include <bits/stdc++.h>


using namespace std;



const int dim = 100100;



ifstream in("ctc.in");

ofstream out("ctc.out");



int n, m, nrc, st[dim], vf, viz[dim];

vector<int> g[dim];

vector<int> gt[dim];

vector<int> cmp[dim];



void push(int x)

{

    if(vf <dim)

        st[++vf] = x;

}



int pop()

{

    if(vf > 0)

        return st[vf--];

}



void read()

{

    in>>n>>m;

    int x, y;

    for(int i = 1;i <= m;i++)

    {

        in>>x>>y;

        g[x].push_back(y);

        gt[y].push_back(x);

    }

}



void dfs1(int st)

{

    viz[st] = 1;

    for(vector<int>::iterator it = g[st].begin(); it != g[st].end();it++)

    {

        if(!viz[*(it)])

            dfs1(*(it));

    }

    push(st);

}



void dfs2(int st)

{

    viz[st] = 1;

    for(vector<int>::iterator it = gt[st].begin(); it != gt[st].end();it++)

    {

        if(!viz[*(it)])

            dfs2(*(it));

    }

    cmp[nrc].push_back(st);

}



void solve()

{

    vf = 0;

    for(int i = 1;i <= n;i++)

    {

        if(!viz[i])

            dfs1(i);

    }

    for(int i = 1;i <= n;i++)

        viz[i] = 0;

    while(vf)

    {

        int curent = pop();

        if(!viz[curent])

        {

            nrc++;

            dfs2(curent);

        }

    }

}



void print()

{

    out<<nrc<<'\n';

    for(int i = 1;i <= nrc;i++)

    {

        for(vector<int>::iterator it = cmp[i].begin(); it != cmp[i].end();it++)

            out<<*(it)<<' ';

        out<<'\n';

    }

}



int main()

{

    read();

    solve();

    print();

    return 0;

}
