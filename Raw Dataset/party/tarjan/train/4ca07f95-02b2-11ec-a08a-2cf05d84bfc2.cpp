#include <bits/stdc++.h>
using namespace std;



ifstream fin("party.in");

ofstream fout("party.out");



vector <int> v[205];



int n, k;



int llink[205], idx[205], ctc[205], ct;



stack<int> st;



bool inst[205];



int NEG(int x)

{

    return n - x;

}



void tarjan(int node)

{

    llink[node] = idx[node] = ++ k;



    inst[node] = true;



    st.push(node);



    for(int i = 0; i < v[node].size(); i++)

        if(idx[v[node][i]] == 0)

    {

        tarjan(v[node][i]);



        llink[node] = min(llink[node], llink[v[node][i]]);

    }

    else

        if(inst[v[node][i]] == true)

            llink[node] = min(llink[node], llink[v[node][i]]);



    if(idx[node] == llink[node])

       {

           int naux = st.top();



           ctc[naux] = ++ct;



           inst[naux] = false;



           st.pop();



           while(naux != node)

           {

                naux = st.top();



                ctc[naux] = ct;



                inst[naux] = false;



                st.pop();

           }

       }

}



int main()

{

    int m;



    fin >> n >> m;



    for(int i = 1; i <= m; i++)

    {

        int x, y, t;



        fin >> x >> y >> t;



        if(t == 0)

        {

         v[NEG(x)].push_back(y + n);

         v[NEG(y)].push_back(x + n);

        }



        if(t == 1)

            {

                v[NEG(x)].push_back(NEG(y));

                v[y + n].push_back(x + n);

            }



        if(t == 2)

            {

                v[x + n].push_back(y + n);

                v[NEG(y)].push_back(NEG(x));

            }



        if(t == 3)

            {

                v[x + n].push_back(NEG(y));

                v[y + n].push_back(NEG(x));

            }

    }



    for(int i = 0; i <= 2 * n; i++)

        if(idx[i] == 0 && i != n)

            tarjan(i);



    int sol[205], kk = 0;



    for(int i = n - 1; i >= 0; i--)

        if(ctc[i] < ctc[2 * n - i])

            continue;

        else

            sol[++kk] = n - i;



    fout << kk << '\n';



    for(int i = 1; i <= kk; i++)

        fout << sol[i] << '\n';

    return 0;

}
