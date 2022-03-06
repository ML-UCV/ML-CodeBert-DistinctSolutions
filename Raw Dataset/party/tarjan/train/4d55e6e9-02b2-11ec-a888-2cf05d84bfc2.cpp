#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream in ("party.in");

ofstream out("party.out");

int n, m, x, y, timp, c;

vector < vector <int> > muchii, componente;

vector <int> disc, low;

stack <int> stk;

vector <char> realVal;

inline int getPoz(int val) {return (val<0) ? -val: val+n;};

inline int getVal(int poz) {return (poz>n) ? poz-n: -poz;};

void tarjrec(int nod)

{

    low[nod]=disc[nod]=++timp;

    stk.push(nod);

    for(auto & x : muchii[nod])

    {

        if(disc[x]==-1)

        {

            tarjrec(x);

            low[nod]=min(low[nod], low[x]);

        }

        else

            low[nod]=min(low[nod], disc[x]);

    }

    if(low[nod]==disc[nod])

    {

        componente.push_back( vector<int>()); int val;

        do

        {

            val=stk.top(); stk.pop();

            componente.back().push_back(val);

            disc[val]=2*n+1;

        }while(val!=nod);

    }

}

inline void Tarjan()

{

    for(int i=1; i<=2*n; i++)

        if(disc[i]==-1)

            tarjrec(i);

}

int main()

{

    in>>n>>m;

    muchii.resize(2*n+1);

    disc.resize(2*n+1, -1); low.resize(2*n+1);

    for(int i=1; i<=m; i++)

    {

        in>>x>>y>>c;

        if(c==1)

            y=-y;

        else if(c==2)

            x=-x;

        else if(c==3)

            x=-x, y=-y;

        muchii[getPoz(-x)].push_back(getPoz(y));

        muchii[getPoz(-y)].push_back(getPoz(x));

    }



    Tarjan(); muchii.clear(); low.clear(); disc.clear();

    muchii.shrink_to_fit(); disc.shrink_to_fit(); low.shrink_to_fit();







    realVal.resize(2*n+1, 0);



    for(auto itr=componente.rbegin(); itr!=componente.rend(); itr++)

        for(auto itr2=itr->begin(); itr2!=itr->end(); itr2++)

            if(realVal[getPoz(-getVal(*itr2))]==0)

                realVal[*itr2]=1, realVal[getPoz(-getVal(*itr2))]=2;



    int rez=0;

    for(int i=1; i<=n; i++)

        if(realVal[i+n]==2)

            rez++;



    out<<rez<<"\n";



    for(int i=1; i<=n; i++)

        if(realVal[i+n]==2)

            out<<i<<"\n";

    return 0;

}
