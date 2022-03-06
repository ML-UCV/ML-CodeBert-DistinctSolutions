#include <iostream>
#include <fstream>
#include <vector>
using namespace std;





ifstream fin("party.in");

ofstream fout("party.out");



typedef vector <int> :: iterator iter;

vector <int> G[205];



int viz[205], st[205], rez[205];



void df(int nod)

{

    viz[nod]=1;

    for(iter it=G[nod].begin();it!=G[nod].end();it++)

    {

        if(!viz[*it])

            df(*it);

    }





    st[++st[0]]=nod-100;

}



int main()

{

    int n, m, x, y, t, i;

    fin>>n>>m;

    while(m--)

    {

        fin>>x>>y>>t;

        if(t==1 || t==3)

            y=-y;

        if(t==2 || t==3)

            x=-x;

        G[-x+100].push_back(y+100);

        G[-y+100].push_back(x+100);

    }

    for(i=-n;i<=n;i++)

    {

        if(i)

        {

            if(!viz[i+100])

                df(i+100);

        }

    }

    for(i=2*n;i>=1;i--)

    {

        if(!rez[st[i]+100] && !rez[-st[i]+100])

        {

            rez[-st[i]+100]=1;

        }

    }

    int s=0;

    for(i=1;i<=n;i++)

    {

        if(rez[i+100])

            s++;

    }

    fout << s << "\n";

    for(i=1;i<=n;i++)

    {

        if(rez[i+100])

            fout << i << "\n";

    }

}
