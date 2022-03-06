#include <cstdio>
#include <cstring>
#include <vector>






using namespace std;



vector <int> G[200005], GT[200005];

int N, TSort[200005], Solution[200005];

bool Used[200005];



inline int Non (int X)

{

    if (X<=N)

    {

        return X+N;

    }

    return X-N;

}



void Read ()

{

    freopen ("party.in", "r", stdin);

    int M;

    scanf ("%d %d", &N, &M);

    for (; M>0; --M)

    {

        int X, Y, Type;

        scanf ("%d %d %d", &X, &Y, &Type);

        if (Type==0)

        {

            G[Non (X)].push_back (Y);

            G[Non (Y)].push_back (X);

            GT[X].push_back (Non (Y));

            GT[Y].push_back (Non (X));

        }

        if (Type==1)

        {

            G[Non (X)].push_back (Non (Y));

            G[Y].push_back (X);

            GT[Non (Y)].push_back (Non (X));

            GT[X].push_back (Y);

        }

        if (Type==2)

        {

            G[Non (Y)].push_back (Non (X));

            G[X].push_back (Y);

            GT[Non (X)].push_back (Non (Y));

            GT[Y].push_back (X);

        }

        if (Type==3)

        {

            G[X].push_back (Non (Y));

            G[Y].push_back (Non (X));

            GT[Non (X)].push_back (Y);

            GT[Non (Y)].push_back (X);

        }

    }

}



void Print ()

{

    freopen ("party.out", "w", stdout);

    for (int i=1; i<=N; ++i)

    {

        Solution[0]+=Solution[i];

    }

    printf ("%d\n", Solution[0]);

    for (int i=1; i<=N; ++i)

    {

        if (Solution[i]!=0)

        {

            printf ("%d\n", i);

        }

    }

}



inline void DFP (int X)

{

    Used[X]=true;

    for (vector <int> :: iterator V=G[X].begin (); V!=G[X].end (); ++V)

    {

        if (!Used[*V])

        {

            DFP (*V);

        }

    }

    TSort[++TSort[0]]=X;

}



inline void DFM (int X)

{

    Used[X]=true;

    Solution[Non (X)]=1;

    for (vector <int> :: iterator V=GT[X].begin (); V!=GT[X].end (); ++V)

    {

        if (!Used[*V])

        {

            DFM (*V);

        }

    }

}



void Kosaraju ()

{

    for (int i=1; i<=N+N; ++i)

    {

        if (!Used[i])

        {

            DFP (i);

        }

    }

    memset (Used, 0, sizeof (Used));

    for (int i=TSort[0]; i>0; --i)

    {

        if (!Used[TSort[i]] and !Used[Non (TSort[i])])

        {

            DFM (TSort[i]);

        }

    }

}



int main()

{

    Read ();

    Kosaraju ();

    Print ();

    return 0;

}
