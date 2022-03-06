#include <bits/stdc++.h>


using namespace std;



ifstream in("party.in");

ofstream out("party.out");



const int nmax = 2007;



vector <int> v[2 * nmax];

vector <int> v_back[2 * nmax];



int n;



int negare(int nod)

{

    return (nod <= n ? nod + n : nod - n);

}



vector <int> st;



bitset <2 * nmax> vis;



int componenta[2 * nmax];



void dfs1(int nod)

{

    vis[nod] = true;



    for(auto i : v[nod])

        if(vis[i] == 0)

            dfs1(i);



    st.push_back(nod);

}



vector <int> CTC[2 * nmax];



int nr;



void dfs2(int nod)

{

    componenta[nod] = nr;



    CTC[nr].push_back(nod);



    for(auto i : v_back[nod])

        if(componenta[i] == 0)

            dfs2(i);

}



bool sol[2 * nmax];



void atrib(int ord)

{

    vis[ord] = false;



    for(auto i : CTC[ord])

    {

        sol[i] = 2;

        sol[negare(i)] = 1;

    }

}



int main()

{

    int m;

    in >> n >> m;



    while(m--)

    {

        int x, y, op;

        in >> x >> y >> op;



        int X = negare(x);

        int Y = negare(y);



        if(op == 0)

        {

            v[X].push_back(y);

            v[Y].push_back(x);



            v_back[y].push_back(X);

            v_back[x].push_back(Y);

        }

        else

            if(op == 1)

            {

                v[X].push_back(Y);

                v[y].push_back(x);



                v_back[Y].push_back(X);

                v_back[x].push_back(y);

            }

            else

                if(op == 2)

                {

                    v[x].push_back(y);

                    v[Y].push_back(X);



                    v_back[y].push_back(x);

                    v_back[X].push_back(Y);

                }

                else

                {

                    v[x].push_back(Y);

                    v[y].push_back(X);



                    v_back[Y].push_back(x);

                    v_back[X].push_back(y);

                }

    }



    for(int i = 1; i <= 2 * n; i++)

        if(vis[i] == 0)

            dfs1(i);



    for(int i = 2 * n; i >= 1; i--)

        if(componenta[st[i - 1]] == 0)

        {

            nr++;



            dfs2(st[i - 1]);

        }



    for(int i = 2 * n - 1; i >= 0; i--)

        if(vis[componenta[st[i]]] == true)

        {

            int nod = st[i];

            int inv = negare(nod);



            vis[componenta[nod]] = false;

            vis[componenta[inv]] = false;



            for(auto j : CTC[componenta[nod]]) sol[j] = false, sol[negare(j)] = true;

        }



    int nr = 0;



    for(int i = 1; i <= n; i++)

        if(sol[i])

            nr++;



    out << nr << '\n';



    for(int i = 1; i <= n; i++)

        if(sol[i])

            out << i << '\n';

}
