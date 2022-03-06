#include <bits/stdc++.h>
using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m, k = 0;



vector <int> v[100005];



vector <vector <int> > sol;



vector <int> temp;



int idx[100005], llink[100005];



bool inst[100005];



stack <int> st;



void tarjan(int node)

{

    idx[node] = llink[node] = ++k;

    st.push(node);

    inst[node] = true;



    for(int i = 0; i < v[node].size(); i++)

        if(idx[v[node][i]] == 0)

    {

        tarjan(v[node][i]);

        llink[node] = min(llink[node], llink[v[node][i]]);

    }

    else

        if(inst[v[node][i]])

            llink[node] = min(llink[node], llink[v[node][i]]);



    if(idx[node] == llink[node])

    {

        temp.clear();



        int naux = 0;



        while(naux != node)

        {

            naux = st.top();



            temp.push_back(naux);



            st.pop();



            inst[naux] = false;

        }



        sol.push_back(temp);

    }



}



int main()

{

    fin >> n >> m;



    for(int i = 1; i <= m; i++)

    {

        int x, y;



        fin >> x >> y;



        v[x].push_back(y);

    }



    for(int i = 1; i <= n; i++)

        if(idx[i] == 0)

            tarjan(i);



    fout << sol.size() << '\n';



    for(int i = 0; i < sol.size(); i++)

    {

        for(int j = 0; j < sol[i].size(); j++)

            fout << sol[i][j] << " ";

        fout << '\n';

    }



    return 0;

}
