#include <bits/stdc++.h>






using namespace std;



vector <int> L[205],T[205],sol;

int ans[205],viz[205],v[205],l,marked[205],n;



inline int non(int x)

{

    if(x<=n) return x+n;

    return x-n;

}



inline void Dfs(int nod)

{

    viz[nod]=1;

    for(auto it : L[nod])

        if(!viz[it]) Dfs(it);

    v[++l]=nod;

}



inline void Dfs1(int nod)

{

    marked[nod]=1;

    ans[nod]=0; ans[non(nod)]=1;

    for(auto it : T[nod])

    {

        if(marked[it]) continue;

        Dfs1(it);

    }

}



int main()

{

    int i,m,x,y,z;

    ifstream cin("party.in");

    ofstream cout("party.out");

    cin>>n>>m;

    while(m--)

    {

        cin>>x>>y>>z;

        if(!z)

        {

            L[non(x)].push_back(y); T[y].push_back(non(x));

            L[non(y)].push_back(x); T[x].push_back(non(y));

        }

        else

            if(z==1)

            {

                L[y].push_back(x); T[x].push_back(y);

            }

            else

                if(z==2)

                {

                    L[x].push_back(y); T[y].push_back(x);

                }

                else

                {

                    L[x].push_back(non(y)); T[non(y)].push_back(x);

                    L[y].push_back(non(x)); T[non(x)].push_back(y);

                }

    }

    for(i=1;i<=2*n;++i)

    {

        if(!viz[i]) Dfs(i);

        ans[i]=-1;

    }



    for(i=2*n;i;--i)

        if(ans[v[i]]==-1) Dfs1(v[i]);



    for(i=1;i<=n;++i)

        if(ans[i]) sol.push_back(i);

    cout<<sol.size()<<"\n";

    for(auto it : sol) cout<<it<<"\n";

    return 0;

}
