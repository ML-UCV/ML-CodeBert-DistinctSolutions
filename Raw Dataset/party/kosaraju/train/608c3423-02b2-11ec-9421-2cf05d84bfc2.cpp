#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

ifstream fin("party.in");

ofstream fout("party.out");

int variables, expressions;

int value[235], discover[235], viz[235], Sol[235];

vector<int> G[235], GT[235];

inline int non(int x)

{

    return (x>variables) ? x-variables : x+variables;

}

void sau(int x, int y)

{

    G[non(x)].push_back(y);

    GT[y].push_back(non(x));

    G[non(y)].push_back(x);

    GT[x].push_back(non(y));

}

void read()

{

    int x, y, z;

    fin>>variables>>expressions;



    for(int i=1;i<=expressions;i++)

    {

        fin>>x>>y>>z;



        switch(z)

        {

            case 0:sau(x, y); break;

            case 1:sau(x, non(y)); break;

            case 2:sau(non(x), y); break;

            case 3:sau(non(x), non(y)); break;

        };

    }

}

void dfs(int node)

{

    viz[node]=1;



    for(vector<int>::iterator it=G[node].begin();it!=G[node].end();it++)

    {

        int fiu=*it;

        if(!viz[fiu])

            dfs(fiu);

    }



    discover[++discover[0]]=node;

}

void dfst(int node)

{

    viz[node]=0;

    value[non(node)]=1;



    for(vector<int>::iterator it=GT[node].begin();it!=GT[node].end();it++)

    {

        int fiu=*it;

        if(viz[fiu])

            dfst(fiu);

    }

}

void _2sat()

{

    for(int i=1;i<=2*variables;i++)

        if(!viz[i])

            dfs(i);



    for(int i=discover[0];i>=1;i--)

        if(viz[discover[i]] && viz[non(discover[i])])

            dfst(discover[i]);

}

void write()

{

    for(int i=1;i<=variables;i++)

        if(value[i])

            Sol[++Sol[0]]=i;



    for(int i=0;i<=Sol[0];i++)

        fout<<Sol[i]<<'\n';

}

int main()

{

    read();

    _2sat();

    write();

    return 0;

}
