#include <bits/stdc++.h>


using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



const int DIM = 1e5 + 7;



vector <int> l[DIM];

vector <int> lt[DIM];



int viz[DIM];



stack <int> s;



vector <int> cc[DIM];



void dfs(int x)

{

    viz[x] = 1;



    for(int i = 0; i < l[x].size(); i++)

    {

        int vec = l[x][i];



        if(viz[vec] == 0)

            dfs(vec);

    }



    s.push(x);



}



void dfst(int x,int cnt)

{

    viz[x] = 2;

    cc[cnt].push_back(x);



    for(int i = 0; i < lt[x].size(); i++)

    {

        int vec = lt[x][i];



        if(viz[vec] == 1)

        {

            dfst(vec,cnt);

        }



    }



}



int main()

{

    int n, m;

    in >> n >> m;



    for(int i = 1; i <= m; i++)

    {

        int x, y;

        in >> x >> y;



        l[x].push_back(y);

        lt[y].push_back(x);

    }



    for(int i = 1; i <= n; i++)

        if(viz[i] == 0)

        {

            dfs(i);

        }



       int cnt = 0;



    while(!s.empty())

    {

        int nod = s.top();

        s.pop();



        if(viz[nod] == 1)

        {

            cnt++;

            dfst(nod,cnt);

        }

    }

    out << cnt <<'\n';



    for(int i = 1; i <= cnt; i++)

        {

          for(int j = 0; j < cc[i].size(); j++)

            out << cc[i][j] <<" ";



            out <<'\n';

        }

    return 0;

}
