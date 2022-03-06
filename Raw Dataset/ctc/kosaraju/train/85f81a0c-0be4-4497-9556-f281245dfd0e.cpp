#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

vector <int> a[200004],b[200004],c[200004],s;

int v[100004],n1,x,y,m,n;

void dfs(int i)

{

    v[i]=1;

    for(int j=0;j<a[i].size();j++)

    {

        int vecin=a[i][j];

        if(v[vecin]==0)

            dfs(vecin);

    }

    s.push_back(i);

}

void dfs1(int i)

{

    v[i]=1;

    c[n1].push_back(i);

    for(int j=0;j<b[i].size();j++)

    {

        int vecin=b[i][j];

        if(v[vecin]==0)

            dfs1(vecin);

    }

}

int main()

{

    fin>>n>>m;

    for(int i=1;i<=m;i++)

    {

        fin>>x>>y;

        a[x].push_back(y);

        b[y].push_back(x);

    }

    for(int i=1;i<=n;i++)

    {

        if(v[i]==0)

            dfs(i);

    }

    for(int i=1;i<=n;i++)

        v[i]=0;



    for(int i=n-1;i>=0;i--)

    {

        if(v[s[i]]==0)

        {

            n1++;

            dfs1(s[i]);

        }

    }

    fout<<n1<<"\n";

    for(int i=1;i<=n1;i++)

    {

        sort(c[i].begin(),c[i].end());

        for(int j=0;j<c[i].size();j++)

            fout<<c[i][j]<<" ";

        fout<<"\n";

    }

    return 0;

}
