#include <bits/stdc++.h>


using namespace std;

ifstream fin ("ctc.in");

ofstream fout ("ctc.out");

struct nodS

{

    int i, low;

    bool on;

    vector <int> vecini;

};

int n,m,x,y,i,t;

stack <int> s;

vector < vector<int> > ans;

nodS nod[100005];

void dfs(int poz)

{

    t++;

    nod[poz].i=t;

    nod[poz].low=t;

    nod[poz].on=true;

    s.push(poz);



    for(int it : nod[poz].vecini)

    {

        if(!nod[it].i)

        {

            dfs(it);

            nod[poz].low=min(nod[poz].low, nod[it].low);

        }

        else if(nod[it].on)

        {

            nod[poz].low=min(nod[poz].low, nod[it].i);

        }

    }



    if(nod[poz].i==nod[poz].low)

    {

        vector <int> nscc;

        while(!s.empty())

        {

            int it=s.top();

            nod[it].on=false;

            nscc.push_back(it);

            s.pop();

            if(it==poz)

                break;

        }

        ans.push_back(nscc);

    }

}

int main()

{

    fin>>n>>m;

    while(m)

    {

        m--;

        fin>>x>>y;

        nod[x].vecini.push_back(y);

    }



    for(i=1;i<=n;i++)

    {

        if(!nod[i].i)

            dfs(i);

    }



    fout<<ans.size()<<'\n';

    for(auto it : ans)

    {

        for(int it2 : it)

            fout<<it2<<' ';

        fout<<'\n';

    }

    return 0;

}
