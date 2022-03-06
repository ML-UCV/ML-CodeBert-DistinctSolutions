#include <iostream>
#include <fstream>
#include <vector>


using namespace std;



ifstream f("party.in");

ofstream g("party.out");







int n,m,i,x,y,z,st,nr;

vector<int> G[210];

int stack[210];

bool X[210],viz[210];
void dfs(int nod)

{

    (viz+100)[nod]=true;

    for(vector<int>:: iterator it=(G+100)[nod].begin();it!=(G+100)[nod].end();++it)

        if(! (viz+100)[*it]) dfs(*it);



    stack[++st]=nod;

}



int main()

{

    f>>n>>m;

    for(i=1;i<=m;++i)

    {

        f>>x>>y>>z;

        switch(z)

        {

            case 0:

            {



                (G+100)[-x].push_back(y);

                (G+100)[-y].push_back(x);

                break;

            }

            case 1:

            {



                (G+100)[-x].push_back(-y);

                (G+100)[y].push_back(x);

                break;

            }

            case 2:

            {



                (G+100)[x].push_back(y);

                (G+100)[-y].push_back(-x);

                break;

            }

            case 3:

            {



                (G+100)[x].push_back(-y);

                (G+100)[y].push_back(-x);

                break;

            }

        }

    }



    for(i=-n;i<=n;++i)

        if(!(viz+100)[i]) dfs(i);



    for(;st;--st)

    {

        if(!(X+100)[stack[st]] && !(X+100)[-stack[st]]) (X+100)[-stack[st]]=true;

    }



    for(i=1;i<=n;++i)

    {

        if ((X+100)[i]) ++nr;

    }

    g<<nr<<'\n';

    for(i=1;i<=n;++i)

    {

        if ((X+100)[i]) g<<i<<'\n';

    }

    return 0;

}
