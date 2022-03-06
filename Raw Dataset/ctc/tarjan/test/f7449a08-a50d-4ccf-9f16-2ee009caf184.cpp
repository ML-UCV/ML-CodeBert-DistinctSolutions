#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<algorithm>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



int n, m, _index = 1;

bool in_st[100100];

int idx[100100], lowlink[100100];

vector<int> graf[100100], componenta;

stack<int> st;

vector<vector<int>> CTC;







void Read()

{

    f>>n>>m;

    for(int i=1;i<=m;i++)

    {

        int x,y;

        f>>x>>y;

        graf[x].push_back(y);

    }

    f.close();

}





void Tarjan(int i)

{

    idx[i] = _index;

    lowlink[i] = _index;

    _index++;

    st.push(i);

    in_st[i] = 1;



    for(int j=0;j<graf[i].size();j++)

    {

        if(idx[graf[i][j]] == 0)

        {

            Tarjan(graf[i][j]);

            lowlink[i] = min(lowlink[i], lowlink[graf[i][j]]);

        }

        else

            if(in_st[graf[i][j]] == 1)

                lowlink[i] = min(lowlink[i], lowlink[graf[i][j]]);

    }



    if(lowlink[i] == idx[i])

    {

        componenta.clear();

        int aux;

        cout<<i<<" ";

        do

        {

            componenta.push_back(aux = st.top());

            st.pop();

            in_st[aux] = 0;

        }

        while(aux != i);

        CTC.push_back(componenta);

    }

}





void Write()

{

    g<<CTC.size()<<'\n';

    for(int i=0;i<CTC.size();i++)

    {

        for(int j=0;j<CTC[i].size();j++)

            g<<CTC[i][j]<<" ";

        g<<'\n';

    }

    g.close();

}
int main()

{

    Read();



    for(int i=1;i<=n;i++)

        if(idx[i] == 0)

            Tarjan(i);



    Write();







    return 0;

}
