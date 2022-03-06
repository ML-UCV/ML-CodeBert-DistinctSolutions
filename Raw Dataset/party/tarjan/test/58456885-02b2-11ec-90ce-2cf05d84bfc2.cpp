#include<bits/stdc++.h>
using namespace std;

ifstream in("party.in");

ofstream out("party.out");

const int NMAX = 105;



vector<int> G[2*NMAX];

vector<int> GT[2*NMAX];

int N,M,ctc[2*NMAX],viz[2*NMAX],st[2*NMAX],nr_ctc,sz,sol[NMAX];



int grad(int a)

{



    if(a > 0)

        return 2*a;

    else

        return -2*a-1;

}



void adauga(int x,int y)

{



    G[grad(-x)].push_back(grad(y));

    G[grad(-y)].push_back(grad(x));



    GT[grad(x)].push_back(grad(-y));

    GT[grad(y)].push_back(grad(-x));

}



void dfs(int nod)

{



    if(viz[nod])

        return;

    viz[nod] = 1;

    for(vector<int>::iterator it = G[nod].begin() ; it != G[nod].end() ; ++it)

        if(!viz[*it])

            dfs(*it);

    st[++sz] = nod;

}



void comp(int nod)

{



    if(!viz[nod])

        return;

    viz[nod] = 0;

    ctc[nod] = nr_ctc;

    for(vector<int>::iterator it = GT[nod].begin() ; it != GT[nod].end() ; ++it)

        if(viz[*it])

            comp(*it);

}



int main()

{



    in>>N>>M;

    int a,b,c;

    for(int i = 1 ; i <= M ; ++i){

        in>>a>>b>>c;

        cout<<a<<" "<<b<<" "<<c<<"\n";

        if(c == 0)

            adauga(a,b);

        else if(c == 1)

            adauga(a,-b);

        else if(c == 2)

            adauga(-a,b);

        else

            adauga(-a,-b);

    }



    for(int i = 1 ; i <= 2 * N ; ++i)

        if(!viz[i])

            dfs(i);

    for(int i = 2 * N ; i > 0 ; --i)

        if(viz[st[i]]){

            ++nr_ctc;

            comp(st[i]);

        }

    int inv = 0;

    for(int i = 1 ; i <= N ; ++i)

        if(ctc[grad(i)] > ctc[grad(-i)]){

            sol[++inv] = i;

        }

    for(int i = 1 ; i <= 2*N ; ++i)

        cout<<ctc[i]<<" ";

    sort(sol + 1,sol + inv + 1);

    out<<inv<<"\n";

    for(int i = 1 ; i <= inv ; ++i)

        out<<sol[i]<<"\n";

    return 0;

}
