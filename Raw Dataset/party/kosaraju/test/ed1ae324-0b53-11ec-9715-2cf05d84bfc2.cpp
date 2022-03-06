#include <fstream>
#include <vector>
#include <cstring>


using namespace std;

ifstream f("party.in");

ofstream g("party.out");

int M,N;

vector <int> G[1005],GT[1005];

int O[1005],Solution[1005],K;

bool Use[1005];

inline int getNode(int x)

{

    if(x<0)

        return N-x;

    return x;

}

inline int nod_negat(int x)

{

    if(x<=N)

        return x+N;

    else

        return x-N;

}

void fillGraph(int x,int y)

{

    GT[x].push_back(nod_negat(y));

    GT[y].push_back(nod_negat(x));

    G[nod_negat(x)].push_back(y);

    G[nod_negat(y)].push_back(x);

}

void cit()

{

    int i,type;

    f>>N>>M;

    for(i=1;i<=M;i++)

    {

        int x,y;

        f>>x>>y>>type;

        if(type==1)

            y*=-1;

        if(type==2)

            x*=-1;

        if(type==3)

        {

            x*=-1;

            y*=-1;

        }

        x=getNode(x);

        y=getNode(y);

        fillGraph(x,y);

    }

}

void DFP(int Nod)

{

    Use[Nod]=1;

    for(unsigned int i=0;i<G[Nod].size();i++)

        {

            int Vecin=G[Nod][i];

            if(!Use[Vecin])

                DFP(Vecin);

        }

    O[++K]=Nod;

}



void DFM(int Nod)

{

    Use[Nod]=1;

    if(Solution[Nod]==1)

    {

        Solution[0]=-1;

        return;

    }

    Solution[nod_negat(Nod)]=1;

    for(unsigned int i=0;i<GT[Nod].size();i++)

        {

            int Vecin=GT[Nod][i];

            if(!Use[Vecin])

                DFM(Vecin);

        }

}



void Kosaraju()

{

    for(int i=1;i<=N*2;i++)

        {

            if(!Use[i])

                DFP(i);

        }

    memset(Use,0,sizeof(Use));

    for(int i=K;i>=1;i--)

        {

            if(!Use[O[i]] && !Use[nod_negat(O[i])])

                DFM(O[i]);

        }

}

void Print()

{

    int i;

    int result=0;

    if(Solution[0]==-1)

    {

        g<<0<<"\n";

        return;

    }

    for(i=1;i<=N;i++)

        if(Solution[i]==1)

            result++;

    g<<result<<"\n";

    for(int i=1;i<=N;i++)

        if(Solution[i]==1)

            g<<i<<"\n";

}

int main()

{

    cit();

    Kosaraju();

    Print();

    return 0;

}
