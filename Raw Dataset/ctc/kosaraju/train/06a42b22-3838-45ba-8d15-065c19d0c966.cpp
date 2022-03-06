#include <fstream>
#include <vector>


using namespace std;

ifstream cin("ctc.in");

ofstream cout("ctc.out");

int viz[100100],viz2[100100],n;

vector <int> sol, G[100100], G_inv[100100], List;

vector < vector <int> > ctc;

void dfs(int nod)

{

    viz[nod]=1;

    for(auto nn:G[nod])

        if(!viz[nn])

            dfs(nn);

    List.push_back(nod);

}



void mark(int nod)

{

    viz2[nod]=ctc.size()+1;

    sol.push_back(nod);

    for(auto nn:G_inv[nod])

        if(!viz2[nn])

            mark(nn);

}



int main()

{

    int m,x,y,el,k=0;

    cin>>n>>m;

    for(int i=1; i<=m; ++i)

    {

        cin>>x>>y;

        G[x].push_back(y);

        G_inv[y].push_back(x);

    }



    for(int i=1; i<=n; ++i)

        if(!viz[i])

        {

            ++k;

            dfs(i);

        }

    while(!List.empty())

    {

        el=List.back();

        if(!viz2[el])

        {

            mark(el);

            ctc.push_back(sol);

            sol.clear();

        }

        List.pop_back();

    }

    cout<<ctc.size()<<'\n';

    for(auto it:ctc)

    {

        for(auto it1:it)

            cout<<it1<<' ';

        cout<<'\n';

    }

    return 0;

}
