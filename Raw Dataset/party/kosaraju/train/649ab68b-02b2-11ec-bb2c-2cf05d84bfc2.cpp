#include <cstdio>
#include <vector>
#include <algorithm>




using namespace std;



vector <int> L[505],T[505];

int Sorted[505],len,sol[505],n;

bool viz[505];



inline int non(int x)

{

    if(x>n) return x-n;

    return x+n;

}



inline void Dfs(int nod)

{

    viz[nod]=true;

    vector <int> ::iterator it;

    for(it=L[nod].begin();it!=L[nod].end();++it)

        if(!viz[*it]) Dfs(*it);

    Sorted[++len]=nod;

}



inline void Dfs2(int nod)

{

    viz[nod]=false; sol[nod]=0; sol[non(nod)]=1;

    vector <int> ::iterator it;

    for(it=T[nod].begin();it!=T[nod].end();++it)

        if(viz[*it]) Dfs2(*it);



}



int main()

{

    int m,x,y,tip,i,cnt;

    freopen ("party.in","r",stdin);

    freopen ("party.out","w",stdout);

    scanf("%d%d", &n,&m);

    while(m--)

    {

        scanf("%d%d%d", &x,&y,&tip);

        if(!tip)

        {

            L[non(x)].push_back(y);

            L[non(y)].push_back(x);

            T[y].push_back(non(x));

            T[x].push_back(non(y));

        }

        else

            if(tip==1)

            {

                L[y].push_back(x);

                T[x].push_back(y);

            }

            else

                if(tip==2)

                {

                    L[x].push_back(y);

                    T[y].push_back(x);

                }

                else

                {

                    L[y].push_back(non(x));

                    L[x].push_back(non(y));

                    T[non(x)].push_back(y);

                    T[non(y)].push_back(x);

                }

    }

    for(i=1;i<=2*n;++i)

        if(!viz[i]) Dfs(i);

    reverse(Sorted+1,Sorted+len+1);

    for(i=1;i<=len;++i)

        if(viz[Sorted[i]] && viz[non(Sorted[i])]) Dfs2(Sorted[i]);

    for(i=1,cnt=0;i<=n;++i) cnt+=(sol[i]==1);

    printf("%d\n", cnt);

    for(i=1;i<=n;++i)

        if(sol[i]) printf("%d\n", i);

    return 0;

}
