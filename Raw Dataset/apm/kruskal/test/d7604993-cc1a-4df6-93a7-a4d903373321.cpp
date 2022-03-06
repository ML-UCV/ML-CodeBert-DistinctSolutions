#include <iostream>
#include <fstream>
#include <algorithm>
std::ifstream in("apm.in");

std::ofstream out("apm.out");

struct graf

{

    int u,v,c,sel;

    bool operator <(const graf&other)const

    {

        return c < other.c;

    }

};

graf v[400005];

int t[200005],h[200005];

int fs(int x)

{

    while(t[x] != x)

        x = t[x];

    return x;

}

void us(int tx,int ty)

{

    if(h[tx] == h[ty])

        t[ty] = tx,h[tx]++;

    else if(h[tx] > h[ty])

        t[ty] = tx;

    else

        t[tx] = ty;

}

void init(int n)

{

    for(int i = 1;i <= n;i++)

        t[i] = i,h[i] = 1;

}

int main()

{

    int n,m;

    in>>n>>m;

    init(n);

    for(int i = 1;i <= m;i++)

        in>>v[i].u>>v[i].v>>v[i].c;

    std::sort(v + 1,v + m + 1);

    int ct = 0,nr = 0,tx,ty;

    for(int i = 1;i <= m && nr < n - 1;i++)

    {

        tx = fs(v[i].u);

        ty = fs(v[i].v);

        if(tx != ty)

        {

            us(tx,ty);

            ct += v[i].c;

            v[i].sel = 1;

            nr++;

        }

    }

    out<<ct<<'\n'<<n-1<<'\n';

    for(int i = 1;i <= m;i++)

    {

        if(v[i].sel == 1)

            out<<v[i].v<<' '<<v[i].u<<'\n';

    }

    return 0;

}
