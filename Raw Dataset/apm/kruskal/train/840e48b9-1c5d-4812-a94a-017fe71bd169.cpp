#include <bits/stdc++.h>


using namespace std;

ifstream fin ("apm.in");

ofstream fout ("apm.out");

struct muchie

{

    int x, y, c;

};

struct cmp

{

    bool operator()(const muchie& a, const muchie& b)

    {

        return a.c > b.c;

    }

};

priority_queue<muchie, vector<muchie>, cmp> q;

vector<pair<int,int>> sol;

void read();

int n, m, rez, t[200005];

int rad(int x)

{

    if(t[x]!=x)

        return (t[x]=rad(t[x]));

    return t[x];

}

void unire(int a, int b, int c)

{

    int r1 = rad(a), r2 = rad(b);

    if(r1!=r2)

    {

        if(rand()%2)

            t[r1] = r2;

        else t[r2] = r1;

        rez+=c;

        sol.push_back({a, b});

    }

}

int main()

{

    read();

    for(int i=1; i<=n; i++)

        t[i] = i;

    while(!q.empty())

    {

        muchie cur = q.top();

        q.pop();

        unire(cur.x, cur.y, cur.c);

    }

    fout << rez << '\n';

    fout << n-1 << '\n';

    for(auto it:sol)

        fout << it.first << ' ' << it.second << '\n';

    return 0;

}

void read()

{

    fin >> n >> m;

    for(int i=1; i<=m; i++)

    {

        muchie w;

        fin >> w.x >> w.y >> w.c;

        q.push(w);

    }

}
