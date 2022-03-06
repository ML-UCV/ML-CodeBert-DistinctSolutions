#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>







using namespace std;
FILE *fin=freopen("swap.in","r",stdin);
FILE *fout=freopen("swap.out","w",stdout);

vector <int> pos[26 + 1];
int p[26 + 1], n, AIB[50050];
char S1[50050], S2[50050];

inline void Add(int pos, int val)
{
    int i;
    for(i = pos; i <= n; i += ((i ^ (i - 1)) & i))
        AIB[i] += val;
}

inline int Query(int pos)
{
    int i, ret = 0;
    for(i = pos; i; i -= ((i ^ (i - 1)) & i))
        ret += AIB[i];
    return ret;
}

void Set()
{
    fgets(S1 , 50001, stdin);
    fgets(S2 , 50001, stdin);
    n = strlen(S1 + 1);
    for(int i = 1; i <= n; ++i)
    {
        pos[ S1[i] - 'a' ].push_back( i );
    }
}

void Solve()
{
    int ans = 0, place;
    int i, l;

    for(i = 1; i <= n; ++i)
    {
        l = S2[i] - 'a';

        if( p[l] >= pos[ l ].size() )
        {
            printf("-1"); return;
        }
        place = pos[ l ][ p[l] ] + Query( n ) - Query( pos[ l ][ p[l] ] );
        ans += abs( i - place );
        Add( pos[ l ][ p[l] ], 1 );
        ++p[l];
    }
    printf("%d", ans);
}

int main()
{
    Set();
    Solve();
    return 0;
}
