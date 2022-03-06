#include <iostream>
#include <fstream>
#include <stack>
#include <vector>


using namespace std;



ifstream f("party.in");

ofstream g("party.out");

int n,m,ID,nr;

stack<int> s;

struct Nod

{

    int id,low;

    int rez;

    bool onstack;

}nod[202];

vector <int> v[202];





void dfs(int i)

{

    nod[i].id = nod[i].low=ID++;

    nod[i].onstack=true;

    s.push(i);

    for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)

    {

        if(nod[*it].id==-1)

            dfs(*it);

        if(nod[*it].onstack)

            nod[i].low=min(nod[i].low,nod[*it].low);

    }

    if(nod[i].id==nod[i].low)

    {

        int node;

        do

        {

            node=s.top();

            s.pop();

            nod[i].onstack=false;

            if(nod[node].rez==-1)

            {

                nod[node].rez=1;

                nod[node^1].rez=0;

                nr+= !(node%2);

            }

        }while(i!=node);

    }

}





int main()

{

    f>>n>>m;

    int x,y,c;

    for(int i=1;i<=m;i++)

    {

        f>>x>>y>>c;

        switch(c)

        {

        case 0:

            v[x*2+1].push_back(y*2);

            v[y*2+1].push_back(x*2);

            break;

        case 1:

            v[x*2+1].push_back(y*2+1);

            v[y*2].push_back(x*2);

            break;

        case 2:

            v[x*2].push_back(y*2);

            v[y*2+1].push_back(x*2+1);

            break;

        case 3:

            v[x*2].push_back(y*2+1);

            v[y*2].push_back(x*2+1);

        }

    }

    for(int i=2;i<=n*2+1;i++)

        nod[i].id=nod[i].rez=-1;

    for(int i=2;i<=n*2+1;i++)

        if(nod[i].id==-1 && nod[i].rez==-1)

            dfs(i);

    g<<nr<<'\n';

    for(int i=2;i<=2*n;i+=2)

        if(nod[i].rez)

            g<<i/2<<' ';

    return 0;

}
