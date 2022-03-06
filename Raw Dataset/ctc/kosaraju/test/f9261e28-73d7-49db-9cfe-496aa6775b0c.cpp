#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>






using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int CMAX = 100015;

int n , m , x , y , comp;

bool viz[CMAX] , viz1[CMAX];



vector < int > v[CMAX];

vector < int > trans[CMAX];

stack < int > st;

vector < int > afis[CMAX];



void citire()

{

    fin >> n >> m;

    for(int i=1;i<=m;i++)

    {

        fin >> x >> y;

        v[x].push_back(y);

        trans[y].push_back(x);

    }

}



void dfs(int nod)

{

    viz[nod] = 1;

    for(int i=0;i<v[nod].size();i++)

    {

        int w = v[nod][i];

        if(viz[w]==0)

        {

            dfs(w);

        }

    }

    st.push(nod);

}



void dfs1(int nod)

{

    viz1[nod] = 1;

    afis[comp].push_back(nod);

    for(int i=0;i<trans[nod].size();i++)

    {

        int w = trans[nod][i];

        if(viz1[w]==0)

        {

            dfs1(w);

        }

    }

}



int main()

{

    citire();



    for(int i=1;i<=n;i++)

    {

        if(viz[i]==0)

        {

            dfs(i);

        }

    }

    comp = 0;



    while(!st.empty())

    {

        if(viz1[st.top()]==0)

        {

            comp++;

            dfs1(st.top());

        }

        st.pop();

    }



    fout << comp << '\n';

    for(int i=1;i<=comp;i++)

    {

        for(int j=0;j<afis[i].size();j++)

        {

            fout << afis[i][j] << " ";

        }

        fout << '\n';

    }

    return 0;

}
