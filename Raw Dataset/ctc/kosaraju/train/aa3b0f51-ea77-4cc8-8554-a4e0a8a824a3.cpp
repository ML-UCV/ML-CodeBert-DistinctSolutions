#include <bits/stdc++.h>


using namespace std;



const int N = 100010;

ifstream f("ctc.in");

ofstream g("ctc.out");

vector <int> v[N];

vector <int> inv[N];



vector <int> answer[N];

stack <int> stiva;

int n, m, k, viz[N];



void DFS(int), DFST(int);

bool myfunction(vector <int> a, vector <int> b)

{

    return a[0] < b[0];

}

int main()

{

    f >> n >> m;

    for(; m; m--)

    {

        int x, y;

        f >> x >> y;

        v[x].push_back(y);

        inv[y].push_back(x);

    }

    for(int i = 1; i <= n; i++)

        if(!viz[i])

            DFS(i);

    while(!stiva.empty())

    {

        int nr = stiva.top();

        stiva.pop();

        if(viz[nr] != 2)

        {

            ++k;

            DFST(nr);



        }

    }

    g << k << '\n';

    for(int i = 1; i <= k; i++, g << '\n')

        for(auto it:answer[i])

            g << it << ' ';



    return 0;

}



void DFS(int nod)

{

    viz[nod] = 1;

    for(auto it:v[nod])

        if(!viz[it])

            DFS(it);

    stiva.push(nod);

}

void DFST(int nod)

{

    viz[nod] = 2;

    answer[k].push_back(nod);

    for(auto it:inv[nod])

        if(viz[it] != 2)

            DFST(it);

}
